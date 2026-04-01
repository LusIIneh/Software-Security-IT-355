#pragma once
#ifndef LICENSEMANAGER_H
#define LICENSEMANAGER_H

#include <vector>
#include <string>
#include "LicenseKey.h"

/**
 * LicenseManager դաս - լիցենզիաների ստեղծման և ստուգման կառավարում
 */
class LicenseManager {
private:
    std::vector<LicenseKey> licenses;
    std::string currentMachineID;

    // Ֆայլից լիցենզիայի վերականգնում և ստուգում
    bool verifyFromFile(const std::string& filename);

    // Գտնել լիցենզիան key-ով
    const LicenseKey* findLicenseByKey(const std::string& licenseKey) const;

public:
    LicenseManager();

    // Մշտական լիցենզիայի ստեղծում
    LicenseKey createPerpetualLicense(const std::string& userName);

    // Ժամանակավոր լիցենզիայի ստեղծում
    LicenseKey createTemporaryLicense(const std::string& userName, int days);

    // Լիցենզիայի ստուգում ըստ key-ի
    bool verifyLicense(const std::string& licenseKey) const;

    // Լիցենզիայի ստուգում ֆայլից
    bool verifyLicenseFile(const std::string& filename);

    // Լիցենզիայի պահպանում ֆայլում
    bool saveToFile(const LicenseKey& license, const std::string& filename);

    // Պահպանում ըստ key-ի
    bool saveLicenseByKey(const std::string& licenseKey, const std::string& filename);

    // Ցուցադրել բոլոր լիցենզիաները
    void listAllLicenses() const;

    // Ընթացիկ մեքենայի ID-ի ստացում
    std::string getCurrentMachineID() const { return currentMachineID; }
};

#endif
