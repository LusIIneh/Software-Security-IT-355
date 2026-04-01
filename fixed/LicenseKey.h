#pragma once
#ifndef LICENSEKEY_H
#define LICENSEKEY_H

#include <string>
#include <ctime>

/**
 * LicenseKey դաս - ներկայացնում է լիցենզիայի ծածկագիրը և դրա հատկությունները
 */
class LicenseKey {
private:
    std::string key;            // Ծածկագիր
    std::string machineID;      // Կապակցված սարքավորման ID
    time_t issueDate;           // Տրման ամսաթիվ
    time_t expiryDate;          // Վավերականության ավարտ (0՝ մշտականի համար)
    std::string licensee;       // Լիցենզառուի անուն
    bool isTemporary;           // Ժամանակավոր լիցենզիա

    // Ծածկագրի գեներացում
    void generateKey();

public:
    // Լռելյայն կոնստրուկտոր
    LicenseKey();

    // Կոնստրուկտոր մշտական լիցենզիայի համար
    LicenseKey(const std::string& machine, const std::string& user);

    // Կոնստրուկտոր ժամանակավոր լիցենզիայի համար
    LicenseKey(const std::string& machine, const std::string& user, int daysValid);

    // Կոնստրուկտոր ֆայլից վերականգնման համար
    LicenseKey(const std::string& machine,
               const std::string& user,
               time_t issue,
               time_t expiry,
               bool temporary);

    // Ստուգում է արդյոք լիցենզիան վավեր է տվյալ մեքենայի համար
    bool isValid(const std::string& currentMachineID) const;

    // Համեմատում է մուտքագրված key-ը
    bool matchesKey(const std::string& otherKey) const;

    // Տպել լիցենզիայի տվյալները
    void printInfo() const;

    // Getter մեթոդներ
    std::string getKey() const { return key; }
    std::string getMachineID() const { return machineID; }
    std::string getLicensee() const { return licensee; }
    time_t getIssueDate() const { return issueDate; }
    time_t getExpiryDate() const { return expiryDate; }
    bool isTemporaryLicense() const { return isTemporary; }
};

#endif
