#include "LicenseKey.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdint>

LicenseKey::LicenseKey()
    : key(""), machineID(""), issueDate(0), expiryDate(0), licensee(""), isTemporary(false) {}

LicenseKey::LicenseKey(const std::string& machine, const std::string& user)
    : machineID(machine), issueDate(time(nullptr)), expiryDate(0), licensee(user), isTemporary(false) {
    generateKey();
}

LicenseKey::LicenseKey(const std::string& machine, const std::string& user, int daysValid)
    : machineID(machine), issueDate(time(nullptr)), licensee(user), isTemporary(true) {
    expiryDate = issueDate + static_cast<time_t>(daysValid) * 24 * 60 * 60;
    generateKey();
}

LicenseKey::LicenseKey(const std::string& machine,
                       const std::string& user,
                       time_t issue,
                       time_t expiry,
                       bool temporary)
    : machineID(machine), issueDate(issue), expiryDate(expiry), licensee(user), isTemporary(temporary) {
    generateKey();
}

void LicenseKey::generateKey() {
    std::string base = machineID + "|" + licensee + "|" +
                       std::to_string(static_cast<long long>(issueDate)) + "|" +
                       std::to_string(static_cast<long long>(expiryDate)) + "|" +
                       (isTemporary ? "TEMP" : "PERM");

    uint64_t hash = 1469598103934665603ULL; // FNV-1a 64-bit
    for (unsigned char c : base) {
        hash ^= c;
        hash *= 1099511628211ULL;
    }

    std::stringstream hexStream;
    hexStream << std::hex << std::uppercase << std::setw(16) << std::setfill('0') << hash;
    std::string raw = hexStream.str();

    std::stringstream formatted;
    for (size_t i = 0; i < raw.size(); ++i) {
        if (i > 0 && i % 4 == 0) {
            formatted << '-';
        }
        formatted << raw[i];
    }

    key = formatted.str();
}

bool LicenseKey::isValid(const std::string& currentMachineID) const {
    if (currentMachineID != machineID) {
        return false;
    }

    if (isTemporary) {
        time_t now = time(nullptr);
        if (now > expiryDate) {
            return false;
        }
    }

    return true;
}

bool LicenseKey::matchesKey(const std::string& otherKey) const {
    return key == otherKey;
}

void LicenseKey::printInfo() const {
    std::cout << "======================================" << std::endl;
    std::cout << "License Key: " << key << std::endl;
    std::cout << "Licensee: " << licensee << std::endl;
    std::cout << "Issue Date: " << ctime(&issueDate);

    if (isTemporary) {
        std::cout << "Valid until: " << ctime(&expiryDate);
        std::cout << "Type: TEMPORARY" << std::endl;
    } else {
        std::cout << "Type: PERPETUAL" << std::endl;
    }

    std::cout << "Machine ID: " << machineID << std::endl;
    std::cout << "======================================" << std::endl;
}
