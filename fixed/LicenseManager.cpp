#include "LicenseManager.h"
#include "HardwareID.h"
#include <iostream>
#include <fstream>
#include <sstream>

LicenseManager::LicenseManager() {
    HardwareID hwid;
    currentMachineID = hwid.getMachineID();

    std::cout << "Current Device ID: " << currentMachineID << std::endl;
    std::cout << "CPU ID: " << hwid.getCpuId() << std::endl;
    std::cout << "MAC address: " << hwid.getMacAddress() << std::endl;
    std::cout << std::endl;
}

LicenseKey LicenseManager::createPerpetualLicense(const std::string& userName) {
    LicenseKey license(currentMachineID, userName);
    licenses.push_back(license);
    return license;
}

LicenseKey LicenseManager::createTemporaryLicense(const std::string& userName, int days) {
    LicenseKey license(currentMachineID, userName, days);
    licenses.push_back(license);
    return license;
}

const LicenseKey* LicenseManager::findLicenseByKey(const std::string& licenseKey) const {
    for (const auto& license : licenses) {
        if (license.matchesKey(licenseKey)) {
            return &license;
        }
    }
    return nullptr;
}

bool LicenseManager::verifyLicense(const std::string& licenseKey) const {
    const LicenseKey* license = findLicenseByKey(licenseKey);
    if (license == nullptr) {
        return false;
    }
    return license->isValid(currentMachineID);
}

bool LicenseManager::saveToFile(const LicenseKey& license, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    file << "KEY=" << license.getKey() << std::endl;
    file << "MACHINE=" << license.getMachineID() << std::endl;
    file << "LICENSEE=" << license.getLicensee() << std::endl;
    file << "ISSUE_DATE=" << static_cast<long long>(license.getIssueDate()) << std::endl;
    file << "EXPIRY_DATE=" << static_cast<long long>(license.getExpiryDate()) << std::endl;
    file << "TYPE=" << (license.isTemporaryLicense() ? "TEMPORARY" : "PERPETUAL") << std::endl;

    file.close();
    return true;
}

bool LicenseManager::saveLicenseByKey(const std::string& licenseKey, const std::string& filename) {
    const LicenseKey* license = findLicenseByKey(licenseKey);
    if (license == nullptr) {
        return false;
    }

    return saveToFile(*license, filename);
}

bool LicenseManager::verifyFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Չհաջողվեց բացել ֆայլը: " << filename << std::endl;
        return false;
    }

    std::string line;
    std::string savedKey;
    std::string savedMachine;
    std::string savedLicensee;
    std::string savedType;
    time_t savedIssueDate = 0;
    time_t savedExpiryDate = 0;

    while (std::getline(file, line)) {
        size_t pos = line.find('=');
        if (pos == std::string::npos) {
            continue;
        }

        std::string name = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        if (name == "KEY") {
            savedKey = value;
        } else if (name == "MACHINE") {
            savedMachine = value;
        } else if (name == "LICENSEE") {
            savedLicensee = value;
        } else if (name == "ISSUE_DATE") {
            savedIssueDate = static_cast<time_t>(std::stoll(value));
        } else if (name == "EXPIRY_DATE") {
            savedExpiryDate = static_cast<time_t>(std::stoll(value));
        } else if (name == "TYPE") {
            savedType = value;
        }
    }

    file.close();

    bool isTemporary = (savedType == "TEMPORARY");

    if (savedMachine != currentMachineID) {
        std::cout << "ՍԽԱԼ. Լիցենզիան նախատեսված չէ այս համակարգչի համար:" << std::endl;
        std::cout << "  Պահանջվում է՝ " << savedMachine << std::endl;
        std::cout << "  Ընթացիկ՝ " << currentMachineID << std::endl;
        return false;
    }

    LicenseKey restored(savedMachine, savedLicensee, savedIssueDate, savedExpiryDate, isTemporary);

    if (!restored.matchesKey(savedKey)) {
        std::cout << "ՍԽԱԼ. Ֆայլում պահված key-ը վնասված է կամ փոփոխված է:" << std::endl;
        return false;
    }

    if (!restored.isValid(currentMachineID)) {
        std::cout << "ՍԽԱԼ. Լիցենզիան ժամկետանց է կամ անվավեր:" << std::endl;
        return false;
    }

    return true;
}

bool LicenseManager::verifyLicenseFile(const std::string& filename) {
    return verifyFromFile(filename);
}

void LicenseManager::listAllLicenses() const {
    if (licenses.empty()) {
        std::cout << "Լիցենզիաներ չեն գտնվել:" << std::endl;
        return;
    }

    std::cout << "\nԲՈԼՈՐ ԼԻՑԵՆԶԻԱՆԵՐԸ:" << std::endl;
    for (const auto& license : licenses) {
        license.printInfo();
    }
}
