<?php

class NextgenObject {
  public function fromData($array) {
    foreach ($array as $key => $value) {

      $setter = 'set' . $key;

      try {
	$method = new ReflectionMethod($this, $setter);
	$params = $method->getParameters();
	$p = $params[0];

	if ($p->getClass() !== NULL) {
	  // instantiate class
          $class = $p->getClass();
          $obj = $class->newInstance();
          $obj->fromData($value);
          $this->$setter($obj);
	} else if ($p->isArray() && is_array($value)) {
	  if (isset($this->_collections[$key])) {
            $elementType = $this->_collections[$key];
            $values = array();
	    foreach ($value as $k => $v) {
	      $el = new $elementType;
              $el->fromData($v);
              $values[] = $el;
	    }

            $this->$setter($values);
	  } else { // must be array of primitives
	    $this->$setter($value);
	  }
	} else {
	  $this->$setter($value);
	}
      } catch (ReflectionException $e) {

      }
    }

  }

  public function toData() {
    $data = array();
    foreach ($this as $key => $value) {
      if (is_object($value)) {
	$data[$key] = $value->toData();
      } else if (is_array($value)) {
	$array = array();
	foreach ($value as $vkey => $vvalue) {
	  if (is_object($vvalue)) {
	    $array[$vkey] = $vvalue->toData();
	  } else {
	    $array[$vkey] = $vvalue;
	  }
	}
	$data[$key] = $array;
      } else {
	$data[$key] = $value;
      }
    }

    return $data;
  }


}

class NextgenRequest extends NextgenObject {
  public function _getService() { return $this->_service; }
  public function _getMethod() { return $this->_method; }
  public function _getResponseClass() { return $this->_response; }
}

// GENERATED CLASSES BELOW
/*
    Equivalent to com.cmcmarkets.crm.api.model.DefaultSubmitApplicationResponse
*/
class SubmitApplicationResponse extends NextgenObject {
  

  public $InvalidAppropriateness;

  public function __construct() {
  }

  public function getInvalidAppropriateness() { return $this->InvalidAppropriateness; }

  public function setInvalidAppropriateness(Appropriateness $a) { $this->InvalidAppropriateness = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.crm.api.model.DefaultAppropriateness
*/
class Appropriateness extends NextgenObject {
  

  public $AgreedToProceed;
  public $KnowledgeAndExperienceScore;
  public $FinancialSuitabilityScore;
  public $AppropriatenessStatus;
  public $AppropriatenessReason;
  public $AssessmentDate;
  public $SeminarAttendedScore;
  public $TradingHistoryOTCScore;
  public $TradingHistorySharesScore;
  public $TradingHistoryETDScore;
  public $WorkExperienceScore;
  public $EducationalQualificationScore;
  public $OwnershipAndRightScore;
  public $ConceptOfMarginAndLeverageScore;
  public $ConceptOfVolatilityScore;
  public $FamiliarWithOnLineScore;
  public $ResponsibilityToMonitorAndManageScore;
  public $UnderstandingOfRiskScore;

  public function __construct() {
  }

  public function getAgreedToProceed() { return $this->AgreedToProceed; }

  public function getKnowledgeAndExperienceScore() { return $this->KnowledgeAndExperienceScore; }

  public function getFinancialSuitabilityScore() { return $this->FinancialSuitabilityScore; }

  public function getAppropriatenessStatus() { return $this->AppropriatenessStatus; }

  public function getAppropriatenessReason() { return $this->AppropriatenessReason; }

  public function getAssessmentDate() { return $this->AssessmentDate; }

  public function getSeminarAttendedScore() { return $this->SeminarAttendedScore; }

  public function getTradingHistoryOTCScore() { return $this->TradingHistoryOTCScore; }

  public function getTradingHistorySharesScore() { return $this->TradingHistorySharesScore; }

  public function getTradingHistoryETDScore() { return $this->TradingHistoryETDScore; }

  public function getWorkExperienceScore() { return $this->WorkExperienceScore; }

  public function getEducationalQualificationScore() { return $this->EducationalQualificationScore; }

  public function getOwnershipAndRightScore() { return $this->OwnershipAndRightScore; }

  public function getConceptOfMarginAndLeverageScore() { return $this->ConceptOfMarginAndLeverageScore; }

  public function getConceptOfVolatilityScore() { return $this->ConceptOfVolatilityScore; }

  public function getFamiliarWithOnLineScore() { return $this->FamiliarWithOnLineScore; }

  public function getResponsibilityToMonitorAndManageScore() { return $this->ResponsibilityToMonitorAndManageScore; }

  public function getUnderstandingOfRiskScore() { return $this->UnderstandingOfRiskScore; }

  public function setAgreedToProceed($a) { $this->AgreedToProceed = $a; return $this; }

  public function setKnowledgeAndExperienceScore($a) { $this->KnowledgeAndExperienceScore = $a; return $this; }

  public function setFinancialSuitabilityScore($a) { $this->FinancialSuitabilityScore = $a; return $this; }

  public function setAppropriatenessStatus($a) { $this->AppropriatenessStatus = $a; return $this; }

  public function setAppropriatenessReason($a) { $this->AppropriatenessReason = $a; return $this; }

  public function setAssessmentDate($a) { $this->AssessmentDate = $a; return $this; }

  public function setSeminarAttendedScore($a) { $this->SeminarAttendedScore = $a; return $this; }

  public function setTradingHistoryOTCScore($a) { $this->TradingHistoryOTCScore = $a; return $this; }

  public function setTradingHistorySharesScore($a) { $this->TradingHistorySharesScore = $a; return $this; }

  public function setTradingHistoryETDScore($a) { $this->TradingHistoryETDScore = $a; return $this; }

  public function setWorkExperienceScore($a) { $this->WorkExperienceScore = $a; return $this; }

  public function setEducationalQualificationScore($a) { $this->EducationalQualificationScore = $a; return $this; }

  public function setOwnershipAndRightScore($a) { $this->OwnershipAndRightScore = $a; return $this; }

  public function setConceptOfMarginAndLeverageScore($a) { $this->ConceptOfMarginAndLeverageScore = $a; return $this; }

  public function setConceptOfVolatilityScore($a) { $this->ConceptOfVolatilityScore = $a; return $this; }

  public function setFamiliarWithOnLineScore($a) { $this->FamiliarWithOnLineScore = $a; return $this; }

  public function setResponsibilityToMonitorAndManageScore($a) { $this->ResponsibilityToMonitorAndManageScore = $a; return $this; }

  public function setUnderstandingOfRiskScore($a) { $this->UnderstandingOfRiskScore = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.crm.api.model.DefaultSubmitApplicationRequest
*/
class SubmitApplicationRequest extends NextgenRequest {
  

  protected $_service = "crm";
  protected $_method = "submitApplication";
  protected $_response = "SubmitApplicationResponse";
  public $Identity;
  public $ApplicationForm;
  public $AppropriatenessSupported;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct($ApplicationForm = NULL, $Identity = NULL, $AppropriatenessSupported = NULL) {
    $this->ApplicationForm = $ApplicationForm;
    $this->Identity = $Identity;
    $this->AppropriatenessSupported = $AppropriatenessSupported;
  }

  public function getIdentity() { return $this->Identity; }

  public function getApplicationForm() { return $this->ApplicationForm; }

  public function getAppropriatenessSupported() { return $this->AppropriatenessSupported; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }

  public function setApplicationForm(ApplicationForm $a) { $this->ApplicationForm = $a; return $this; }

  public function setAppropriatenessSupported($a) { $this->AppropriatenessSupported = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.framework.messaging.common.model.DefaultIdentity
*/
class Identity extends NextgenObject {
  

  public $Id;

  public function __construct($Id = NULL) {
    $this->Id = $Id;
  }

  public function getId() { return $this->Id; }

  public function setId($a) { $this->Id = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.crm.api.model.DefaultApplicationForm
*/
class ApplicationForm extends NextgenObject {
    protected $_collections = array (
  'TelephoneNumbers' => 'TelephoneNumber',
);

  public $Address;
  public $Language;
  public $Id;
  public $Version;
  public $Currency;
  public $IdentityDetails;
  public $FirstName;
  public $LastName;
  public $DateOfBirth;
  public $DeviceID;
  public $EmailAddress;
  public $IpAddress;
  public $TenantTemplateCode;
  public $ProductWrapperCode;
  public $AddressId;
  public $TitleId;
  public $Title;
  public $Nationality;
  public $TelephoneNumbers;
  public $EmploymentDetails;
  public $FinancialDetails;
  public $TradingExperienceDetails;
  public $ReceiveMarketingData;
  public $TermsAndConditions;
  public $Appropriateness;
  public $TenantID;
  public $Office;
  public $ProfitCentre;
  public $Product;
  public $BankDetails;
  public $Gender;
  public $TermsOfBusinessName;
  public $TermsOfBusinessVersion;
  public $TermsOfBusinessAcceptanceTime;
  public $AcceptanceOfCKAAssessment;
  public $UnderstandingOfRisk;
  public $CreditConsentGiven;
  public $DOBDay;
  public $DOBMonth;
  public $DOBYear;
  public $ApplicationType;
  public $SalesTraderFlag;

  public function __construct() {
  }

  public function getAddress() { return $this->Address; }

  public function getLanguage() { return $this->Language; }

  public function getId() { return $this->Id; }

  public function getVersion() { return $this->Version; }

  public function getCurrency() { return $this->Currency; }

  public function getIdentityDetails() { return $this->IdentityDetails; }

  public function getFirstName() { return $this->FirstName; }

  public function getLastName() { return $this->LastName; }

  public function getDateOfBirth() { return $this->DateOfBirth; }

  public function getDeviceID() { return $this->DeviceID; }

  public function getEmailAddress() { return $this->EmailAddress; }

  public function getIpAddress() { return $this->IpAddress; }

  public function getTenantTemplateCode() { return $this->TenantTemplateCode; }

  public function getProductWrapperCode() { return $this->ProductWrapperCode; }

  public function getAddressId() { return $this->AddressId; }

  public function getTitleId() { return $this->TitleId; }

  public function getTitle() { return $this->Title; }

  public function getNationality() { return $this->Nationality; }

  public function getTelephoneNumbers() { return $this->TelephoneNumbers; }

  public function getEmploymentDetails() { return $this->EmploymentDetails; }

  public function getFinancialDetails() { return $this->FinancialDetails; }

  public function getTradingExperienceDetails() { return $this->TradingExperienceDetails; }

  public function getReceiveMarketingData() { return $this->ReceiveMarketingData; }

  public function getTermsAndConditions() { return $this->TermsAndConditions; }

  public function getAppropriateness() { return $this->Appropriateness; }

  public function getTenantID() { return $this->TenantID; }

  public function getOffice() { return $this->Office; }

  public function getProfitCentre() { return $this->ProfitCentre; }

  public function getProduct() { return $this->Product; }

  public function getBankDetails() { return $this->BankDetails; }

  public function getGender() { return $this->Gender; }

  public function getTermsOfBusinessName() { return $this->TermsOfBusinessName; }

  public function getTermsOfBusinessVersion() { return $this->TermsOfBusinessVersion; }

  public function getTermsOfBusinessAcceptanceTime() { return $this->TermsOfBusinessAcceptanceTime; }

  public function getAcceptanceOfCKAAssessment() { return $this->AcceptanceOfCKAAssessment; }

  public function getUnderstandingOfRisk() { return $this->UnderstandingOfRisk; }

  public function getCreditConsentGiven() { return $this->CreditConsentGiven; }

  public function getDOBDay() { return $this->DOBDay; }

  public function getDOBMonth() { return $this->DOBMonth; }

  public function getDOBYear() { return $this->DOBYear; }

  public function getApplicationType() { return $this->ApplicationType; }

  public function getSalesTraderFlag() { return $this->SalesTraderFlag; }

  public function setAddress(Address $a) { $this->Address = $a; return $this; }

  public function setLanguage($a) { $this->Language = $a; return $this; }

  public function setId($a) { $this->Id = $a; return $this; }

  public function setVersion($a) { $this->Version = $a; return $this; }

  public function setCurrency($a) { $this->Currency = $a; return $this; }

  public function setIdentityDetails(IdentityDetails $a) { $this->IdentityDetails = $a; return $this; }

  public function setFirstName($a) { $this->FirstName = $a; return $this; }

  public function setLastName($a) { $this->LastName = $a; return $this; }

  public function setDateOfBirth($a) { $this->DateOfBirth = $a; return $this; }

  public function setDeviceID($a) { $this->DeviceID = $a; return $this; }

  public function setEmailAddress(EmailAddress $a) { $this->EmailAddress = $a; return $this; }

  public function setIpAddress($a) { $this->IpAddress = $a; return $this; }

  public function setTenantTemplateCode($a) { $this->TenantTemplateCode = $a; return $this; }

  public function setProductWrapperCode($a) { $this->ProductWrapperCode = $a; return $this; }

  public function setAddressId($a) { $this->AddressId = $a; return $this; }

  public function setTitleId($a) { $this->TitleId = $a; return $this; }

  public function setTitle($a) { $this->Title = $a; return $this; }

  public function setNationality($a) { $this->Nationality = $a; return $this; }

  public function setTelephoneNumbers(array $a) { $this->TelephoneNumbers = $a; return $this; }

  public function setEmploymentDetails(EmploymentDetails $a) { $this->EmploymentDetails = $a; return $this; }

  public function setFinancialDetails(FinancialDetails $a) { $this->FinancialDetails = $a; return $this; }

  public function setTradingExperienceDetails(TradingExperienceDetails $a) { $this->TradingExperienceDetails = $a; return $this; }

  public function setReceiveMarketingData($a) { $this->ReceiveMarketingData = $a; return $this; }

  public function setTermsAndConditions($a) { $this->TermsAndConditions = $a; return $this; }

  public function setAppropriateness(Appropriateness $a) { $this->Appropriateness = $a; return $this; }

  public function setTenantID($a) { $this->TenantID = $a; return $this; }

  public function setOffice($a) { $this->Office = $a; return $this; }

  public function setProfitCentre($a) { $this->ProfitCentre = $a; return $this; }

  public function setProduct($a) { $this->Product = $a; return $this; }

  public function setBankDetails(BankDetails $a) { $this->BankDetails = $a; return $this; }

  public function setGender($a) { $this->Gender = $a; return $this; }

  public function setTermsOfBusinessName($a) { $this->TermsOfBusinessName = $a; return $this; }

  public function setTermsOfBusinessVersion($a) { $this->TermsOfBusinessVersion = $a; return $this; }

  public function setTermsOfBusinessAcceptanceTime($a) { $this->TermsOfBusinessAcceptanceTime = $a; return $this; }

  public function setAcceptanceOfCKAAssessment($a) { $this->AcceptanceOfCKAAssessment = $a; return $this; }

  public function setUnderstandingOfRisk(UnderstandingOfRisk $a) { $this->UnderstandingOfRisk = $a; return $this; }

  public function setCreditConsentGiven($a) { $this->CreditConsentGiven = $a; return $this; }

  public function setDOBDay($a) { $this->DOBDay = $a; return $this; }

  public function setDOBMonth($a) { $this->DOBMonth = $a; return $this; }

  public function setDOBYear($a) { $this->DOBYear = $a; return $this; }

  public function setApplicationType($a) { $this->ApplicationType = $a; return $this; }

  public function setSalesTraderFlag($a) { $this->SalesTraderFlag = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.customermaster.api.model.DefaultAddress
*/
class Address extends NextgenObject {
  

  public $Id;
  public $Type;
  public $Country;
  public $Version;
  public $Primary;
  public $AddressLine1;
  public $AddressLine2;
  public $AddressLine3;
  public $AddressLine4;
  public $AddressLine5;
  public $PostalCode;
  public $Previous;
  public $YearsAtAddress;
  public $IsDeleted;

  public function __construct() {
  }

  public function getId() { return $this->Id; }

  public function getType() { return $this->Type; }

  public function getCountry() { return $this->Country; }

  public function getVersion() { return $this->Version; }

  public function getPrimary() { return $this->Primary; }

  public function getAddressLine1() { return $this->AddressLine1; }

  public function getAddressLine2() { return $this->AddressLine2; }

  public function getAddressLine3() { return $this->AddressLine3; }

  public function getAddressLine4() { return $this->AddressLine4; }

  public function getAddressLine5() { return $this->AddressLine5; }

  public function getPostalCode() { return $this->PostalCode; }

  public function getPrevious() { return $this->Previous; }

  public function getYearsAtAddress() { return $this->YearsAtAddress; }

  public function getIsDeleted() { return $this->IsDeleted; }

  public function setId($a) { $this->Id = $a; return $this; }

  public function setType($a) { $this->Type = $a; return $this; }

  public function setCountry($a) { $this->Country = $a; return $this; }

  public function setVersion($a) { $this->Version = $a; return $this; }

  public function setPrimary($a) { $this->Primary = $a; return $this; }

  public function setAddressLine1($a) { $this->AddressLine1 = $a; return $this; }

  public function setAddressLine2($a) { $this->AddressLine2 = $a; return $this; }

  public function setAddressLine3($a) { $this->AddressLine3 = $a; return $this; }

  public function setAddressLine4($a) { $this->AddressLine4 = $a; return $this; }

  public function setAddressLine5($a) { $this->AddressLine5 = $a; return $this; }

  public function setPostalCode($a) { $this->PostalCode = $a; return $this; }

  public function setPrevious($a) { $this->Previous = $a; return $this; }

  public function setYearsAtAddress($a) { $this->YearsAtAddress = $a; return $this; }

  public function setIsDeleted($a) { $this->IsDeleted = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.crm.api.model.DefaultIdentityDetails
*/
class IdentityDetails extends NextgenObject {
  

  public $Type;
  public $Identification;
  public $AdditionalDetails;
  public $ExpiryDate;

  public function __construct() {
  }

  public function getType() { return $this->Type; }

  public function getIdentification() { return $this->Identification; }

  public function getAdditionalDetails() { return $this->AdditionalDetails; }

  public function getExpiryDate() { return $this->ExpiryDate; }

  public function setType($a) { $this->Type = $a; return $this; }

  public function setIdentification($a) { $this->Identification = $a; return $this; }

  public function setAdditionalDetails($a) { $this->AdditionalDetails = $a; return $this; }

  public function setExpiryDate($a) { $this->ExpiryDate = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.customermaster.api.model.DefaultEmailAddress
*/
class EmailAddress extends NextgenObject {
  

  public $Id;
  public $Type;
  public $Version;
  public $Primary;
  public $EmailAddress;
  public $IsDeleted;

  public function __construct() {
  }

  public function getId() { return $this->Id; }

  public function getType() { return $this->Type; }

  public function getVersion() { return $this->Version; }

  public function getPrimary() { return $this->Primary; }

  public function getEmailAddress() { return $this->EmailAddress; }

  public function getIsDeleted() { return $this->IsDeleted; }

  public function setId($a) { $this->Id = $a; return $this; }

  public function setType($a) { $this->Type = $a; return $this; }

  public function setVersion($a) { $this->Version = $a; return $this; }

  public function setPrimary($a) { $this->Primary = $a; return $this; }

  public function setEmailAddress($a) { $this->EmailAddress = $a; return $this; }

  public function setIsDeleted($a) { $this->IsDeleted = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.customermaster.api.model.DefaultTelephoneNumber
*/
class TelephoneNumber extends NextgenObject {
  

  public $Id;
  public $Type;
  public $Version;
  public $Primary;
  public $IsDeleted;
  public $TelephoneNumber;

  public function __construct() {
  }

  public function getId() { return $this->Id; }

  public function getType() { return $this->Type; }

  public function getVersion() { return $this->Version; }

  public function getPrimary() { return $this->Primary; }

  public function getIsDeleted() { return $this->IsDeleted; }

  public function getTelephoneNumber() { return $this->TelephoneNumber; }

  public function setId($a) { $this->Id = $a; return $this; }

  public function setType($a) { $this->Type = $a; return $this; }

  public function setVersion($a) { $this->Version = $a; return $this; }

  public function setPrimary($a) { $this->Primary = $a; return $this; }

  public function setIsDeleted($a) { $this->IsDeleted = $a; return $this; }

  public function setTelephoneNumber($a) { $this->TelephoneNumber = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.customermaster.api.model.DefaultEmploymentDetails
*/
class EmploymentDetails extends NextgenObject {
    protected $_collections = array (
  'ComplianceEmailAddresses2' => 'ComplianceEmailAddress',
);

  public $Id;
  public $Version;
  public $EmploymentStatus;
  public $JobTitle;
  public $CompanyName;
  public $NatureOfBusiness;
  public $FsaRegulated;
  public $ComplianceEmailAddresses;
  public $ComplianceEmailAddresses2;
  public $CompanyRegistrationNumber;

  public function __construct() {
  }

  public function getId() { return $this->Id; }

  public function getVersion() { return $this->Version; }

  public function getEmploymentStatus() { return $this->EmploymentStatus; }

  public function getJobTitle() { return $this->JobTitle; }

  public function getCompanyName() { return $this->CompanyName; }

  public function getNatureOfBusiness() { return $this->NatureOfBusiness; }

  public function getFsaRegulated() { return $this->FsaRegulated; }

  public function getComplianceEmailAddresses() { return $this->ComplianceEmailAddresses; }

  public function getComplianceEmailAddresses2() { return $this->ComplianceEmailAddresses2; }

  public function getCompanyRegistrationNumber() { return $this->CompanyRegistrationNumber; }

  public function setId($a) { $this->Id = $a; return $this; }

  public function setVersion($a) { $this->Version = $a; return $this; }

  public function setEmploymentStatus($a) { $this->EmploymentStatus = $a; return $this; }

  public function setJobTitle($a) { $this->JobTitle = $a; return $this; }

  public function setCompanyName($a) { $this->CompanyName = $a; return $this; }

  public function setNatureOfBusiness($a) { $this->NatureOfBusiness = $a; return $this; }

  public function setFsaRegulated($a) { $this->FsaRegulated = $a; return $this; }

  public function setComplianceEmailAddresses(array $a) { $this->ComplianceEmailAddresses = $a; return $this; }

  public function setComplianceEmailAddresses2(array $a) { $this->ComplianceEmailAddresses2 = $a; return $this; }

  public function setCompanyRegistrationNumber($a) { $this->CompanyRegistrationNumber = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.customermaster.api.model.DefaultComplianceEmailAddress
*/
class ComplianceEmailAddress extends NextgenObject {
  

  public $Id;
  public $Deleted;
  public $EmailAddress;
  public $IsDeleted;

  public function __construct() {
  }

  public function getId() { return $this->Id; }

  public function getDeleted() { return $this->Deleted; }

  public function getEmailAddress() { return $this->EmailAddress; }

  public function getIsDeleted() { return $this->IsDeleted; }

  public function setId($a) { $this->Id = $a; return $this; }

  public function setDeleted($a) { $this->Deleted = $a; return $this; }

  public function setEmailAddress($a) { $this->EmailAddress = $a; return $this; }

  public function setIsDeleted($a) { $this->IsDeleted = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.customermaster.api.model.DefaultFinancialDetails
*/
class FinancialDetails extends NextgenObject {
  

  public $Id;
  public $Version;
  public $AnnualIncome;
  public $AnnualIncomeCurrency;
  public $NetWorth;
  public $NetWorthCurrency;
  public $OriginOfWealth;
  public $OriginOfWealthDetails;
  public $SourceOfFunds;
  public $SourceOfFundsDetails;

  public function __construct() {
  }

  public function getId() { return $this->Id; }

  public function getVersion() { return $this->Version; }

  public function getAnnualIncome() { return $this->AnnualIncome; }

  public function getAnnualIncomeCurrency() { return $this->AnnualIncomeCurrency; }

  public function getNetWorth() { return $this->NetWorth; }

  public function getNetWorthCurrency() { return $this->NetWorthCurrency; }

  public function getOriginOfWealth() { return $this->OriginOfWealth; }

  public function getOriginOfWealthDetails() { return $this->OriginOfWealthDetails; }

  public function getSourceOfFunds() { return $this->SourceOfFunds; }

  public function getSourceOfFundsDetails() { return $this->SourceOfFundsDetails; }

  public function setId($a) { $this->Id = $a; return $this; }

  public function setVersion($a) { $this->Version = $a; return $this; }

  public function setAnnualIncome($a) { $this->AnnualIncome = $a; return $this; }

  public function setAnnualIncomeCurrency($a) { $this->AnnualIncomeCurrency = $a; return $this; }

  public function setNetWorth($a) { $this->NetWorth = $a; return $this; }

  public function setNetWorthCurrency($a) { $this->NetWorthCurrency = $a; return $this; }

  public function setOriginOfWealth($a) { $this->OriginOfWealth = $a; return $this; }

  public function setOriginOfWealthDetails($a) { $this->OriginOfWealthDetails = $a; return $this; }

  public function setSourceOfFunds($a) { $this->SourceOfFunds = $a; return $this; }

  public function setSourceOfFundsDetails($a) { $this->SourceOfFundsDetails = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.crm.api.model.DefaultTradingExperienceDetails
*/
class TradingExperienceDetails extends NextgenObject {
    protected $_collections = array (
  'TradingExperiences' => 'TradingExperience',
);

  public $ID;
  public $TradingExperiences;
  public $SeminarAttended;
  public $ProfessionalExperience;
  public $ProfessionalExperienceDetails;
  public $ProfessionalExperienceCode;
  public $NoOfYearsExperienceCode;
  public $WorkExperienceResult;
  public $WorkExperienceCode;
  public $EducationalDetails;
  public $RelevantInvestmentExperience;

  public function __construct() {
  }

  public function getID() { return $this->ID; }

  public function getTradingExperiences() { return $this->TradingExperiences; }

  public function getSeminarAttended() { return $this->SeminarAttended; }

  public function getProfessionalExperience() { return $this->ProfessionalExperience; }

  public function getProfessionalExperienceDetails() { return $this->ProfessionalExperienceDetails; }

  public function getProfessionalExperienceCode() { return $this->ProfessionalExperienceCode; }

  public function getNoOfYearsExperienceCode() { return $this->NoOfYearsExperienceCode; }

  public function getWorkExperienceResult() { return $this->WorkExperienceResult; }

  public function getWorkExperienceCode() { return $this->WorkExperienceCode; }

  public function getEducationalDetails() { return $this->EducationalDetails; }

  public function getRelevantInvestmentExperience() { return $this->RelevantInvestmentExperience; }

  public function setID($a) { $this->ID = $a; return $this; }

  public function setTradingExperiences(array $a) { $this->TradingExperiences = $a; return $this; }

  public function setSeminarAttended($a) { $this->SeminarAttended = $a; return $this; }

  public function setProfessionalExperience($a) { $this->ProfessionalExperience = $a; return $this; }

  public function setProfessionalExperienceDetails($a) { $this->ProfessionalExperienceDetails = $a; return $this; }

  public function setProfessionalExperienceCode($a) { $this->ProfessionalExperienceCode = $a; return $this; }

  public function setNoOfYearsExperienceCode($a) { $this->NoOfYearsExperienceCode = $a; return $this; }

  public function setWorkExperienceResult($a) { $this->WorkExperienceResult = $a; return $this; }

  public function setWorkExperienceCode($a) { $this->WorkExperienceCode = $a; return $this; }

  public function setEducationalDetails(EducationalDetails $a) { $this->EducationalDetails = $a; return $this; }

  public function setRelevantInvestmentExperience(RelevantInvestmentExperience $a) { $this->RelevantInvestmentExperience = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.crm.api.model.DefaultTradingExperience
*/
class TradingExperience extends NextgenObject {
  

  public $ID;
  public $TradingType;
  public $AverageDealSize;
  public $AverageDealSizeCurrency;
  public $NumberOfTrades;
  public $TradingFrequency;
  public $TradingFrequencyCode;
  public $TradingHistoryCode;

  public function __construct() {
  }

  public function getID() { return $this->ID; }

  public function getTradingType() { return $this->TradingType; }

  public function getAverageDealSize() { return $this->AverageDealSize; }

  public function getAverageDealSizeCurrency() { return $this->AverageDealSizeCurrency; }

  public function getNumberOfTrades() { return $this->NumberOfTrades; }

  public function getTradingFrequency() { return $this->TradingFrequency; }

  public function getTradingFrequencyCode() { return $this->TradingFrequencyCode; }

  public function getTradingHistoryCode() { return $this->TradingHistoryCode; }

  public function setID($a) { $this->ID = $a; return $this; }

  public function setTradingType($a) { $this->TradingType = $a; return $this; }

  public function setAverageDealSize($a) { $this->AverageDealSize = $a; return $this; }

  public function setAverageDealSizeCurrency($a) { $this->AverageDealSizeCurrency = $a; return $this; }

  public function setNumberOfTrades($a) { $this->NumberOfTrades = $a; return $this; }

  public function setTradingFrequency($a) { $this->TradingFrequency = $a; return $this; }

  public function setTradingFrequencyCode($a) { $this->TradingFrequencyCode = $a; return $this; }

  public function setTradingHistoryCode($a) { $this->TradingHistoryCode = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.crm.api.model.EducationalDetails
*/
class EducationalDetails extends NextgenObject {
  

  public $EducationalQualificationsCode;
  public $EducationalQualificationResult;

  public function __construct() {
  }

  public function getEducationalQualificationsCode() { return $this->EducationalQualificationsCode; }

  public function getEducationalQualificationResult() { return $this->EducationalQualificationResult; }

  public function setEducationalQualificationsCode($a) { $this->EducationalQualificationsCode = $a; return $this; }

  public function setEducationalQualificationResult($a) { $this->EducationalQualificationResult = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.crm.api.model.DefaultRelevantInvestmentExperience
*/
class RelevantInvestmentExperience extends NextgenObject {
  

  public $InvestmentExperienceCode;
  public $NoOfTransactionsCode;
  public $InvestmentExperienceResult;

  public function __construct() {
  }

  public function getInvestmentExperienceCode() { return $this->InvestmentExperienceCode; }

  public function getNoOfTransactionsCode() { return $this->NoOfTransactionsCode; }

  public function getInvestmentExperienceResult() { return $this->InvestmentExperienceResult; }

  public function setInvestmentExperienceCode($a) { $this->InvestmentExperienceCode = $a; return $this; }

  public function setNoOfTransactionsCode($a) { $this->NoOfTransactionsCode = $a; return $this; }

  public function setInvestmentExperienceResult($a) { $this->InvestmentExperienceResult = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.crm.api.model.DefaultBankDetails
*/
class BankDetails extends NextgenObject {
  

  public $SortCode;
  public $AccountNumber;
  public $Iban;
  public $IsValid;
  public $AccountCountry;

  public function __construct() {
  }

  public function getSortCode() { return $this->SortCode; }

  public function getAccountNumber() { return $this->AccountNumber; }

  public function getIban() { return $this->Iban; }

  public function getIsValid() { return $this->IsValid; }

  public function getAccountCountry() { return $this->AccountCountry; }

  public function setSortCode($a) { $this->SortCode = $a; return $this; }

  public function setAccountNumber($a) { $this->AccountNumber = $a; return $this; }

  public function setIban($a) { $this->Iban = $a; return $this; }

  public function setIsValid($a) { $this->IsValid = $a; return $this; }

  public function setAccountCountry($a) { $this->AccountCountry = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.crm.api.model.DefaultUnderstandingOfRisk
*/
class UnderstandingOfRisk extends NextgenObject {
  

  public $OwnershipAndRights;
  public $ConceptOfMarginAndLeverage;
  public $ConceptOfVolatility;
  public $FamiliarWithOnlinePlatform;
  public $ResponsibilityToMonitorAndManage;

  public function __construct() {
  }

  public function getOwnershipAndRights() { return $this->OwnershipAndRights; }

  public function getConceptOfMarginAndLeverage() { return $this->ConceptOfMarginAndLeverage; }

  public function getConceptOfVolatility() { return $this->ConceptOfVolatility; }

  public function getFamiliarWithOnlinePlatform() { return $this->FamiliarWithOnlinePlatform; }

  public function getResponsibilityToMonitorAndManage() { return $this->ResponsibilityToMonitorAndManage; }

  public function setOwnershipAndRights($a) { $this->OwnershipAndRights = $a; return $this; }

  public function setConceptOfMarginAndLeverage($a) { $this->ConceptOfMarginAndLeverage = $a; return $this; }

  public function setConceptOfVolatility($a) { $this->ConceptOfVolatility = $a; return $this; }

  public function setFamiliarWithOnlinePlatform($a) { $this->FamiliarWithOnlinePlatform = $a; return $this; }

  public function setResponsibilityToMonitorAndManage($a) { $this->ResponsibilityToMonitorAndManage = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultAuthenticationResponse
*/
class AuthenticationResponse extends NextgenObject {
    protected $_collections = array (
  'IdentityAttributes' => 'Attribute',
);

  public $Identity;
  public $IdentityAttributes;
  public $AuthenticationToken;
  public $CredentialExpiryTimes;
  public $AuthenticationTime;

  public function __construct() {
  }

  public function getIdentity() { return $this->Identity; }

  public function getIdentityAttributes() { return $this->IdentityAttributes; }

  public function getAuthenticationToken() { return $this->AuthenticationToken; }

  public function getCredentialExpiryTimes() { return $this->CredentialExpiryTimes; }

  public function getAuthenticationTime() { return $this->AuthenticationTime; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }

  public function setIdentityAttributes(array $a) { $this->IdentityAttributes = $a; return $this; }

  public function setAuthenticationToken(AuthenticationToken $a) { $this->AuthenticationToken = $a; return $this; }

  public function setCredentialExpiryTimes(array $a) { $this->CredentialExpiryTimes = $a; return $this; }

  public function setAuthenticationTime($a) { $this->AuthenticationTime = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.framework.messaging.common.model.DefaultAttribute
*/
class Attribute extends NextgenObject {
  

  public $Name;
  public $Value;

  public function __construct($Name = NULL, $Value = NULL) {
    $this->Name = $Name;
    $this->Value = $Value;
  }

  public function getName() { return $this->Name; }

  public function getValue() { return $this->Value; }

  public function setName($a) { $this->Name = $a; return $this; }

  public function setValue($a) { $this->Value = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultAuthenticationToken
*/
class AuthenticationToken extends NextgenObject {
  

  public $Token;

  public function __construct($Token = NULL) {
    $this->Token = $Token;
  }

  public function getToken() { return $this->Token; }

  public function setToken($a) { $this->Token = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultInternalAuthenticationRequest
*/
class InternalAuthenticationRequest extends NextgenRequest {
    protected $_collections = array (
  'IdentityAttributes' => 'Attribute',
  'ChallengeResponses' => 'PartialCredentialChallengeResponse',
  'Credentials' => 'Credential',
);

  protected $_service = "identity";
  protected $_method = "authenticate";
  protected $_response = "AuthenticationResponse";
  public $Identity;
  public $IdentityAttributes;
  public $ChallengeResponses;
  public $Credentials;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getIdentity() { return $this->Identity; }

  public function getIdentityAttributes() { return $this->IdentityAttributes; }

  public function getChallengeResponses() { return $this->ChallengeResponses; }

  public function getCredentials() { return $this->Credentials; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }

  public function setIdentityAttributes(array $a) { $this->IdentityAttributes = $a; return $this; }

  public function setChallengeResponses(array $a) { $this->ChallengeResponses = $a; return $this; }

  public function setCredentials(array $a) { $this->Credentials = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultPartialCredentialChallengeResponse
*/
class PartialCredentialChallengeResponse extends NextgenObject {
  

  public $ChallengeID;
  public $Characters;

  public function __construct($ChallengeID = NULL, $Characters = NULL) {
    $this->ChallengeID = $ChallengeID;
    $this->Characters = $Characters;
  }

  public function getChallengeID() { return $this->ChallengeID; }

  public function getCharacters() { return $this->Characters; }

  public function setChallengeID($a) { $this->ChallengeID = $a; return $this; }

  public function setCharacters(array $a) { $this->Characters = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultCredential
*/
class Credential extends NextgenObject {
  

  public $Name;
  public $Value;

  public function __construct($Name = NULL, $Value = NULL) {
    $this->Name = $Name;
    $this->Value = $Value;
  }

  public function getName() { return $this->Name; }

  public function getValue() { return $this->Value; }

  public function setName($a) { $this->Name = $a; return $this; }

  public function setValue($a) { $this->Value = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultExternalAuthenticationRequest
*/
class ExternalAuthenticationRequest extends NextgenRequest {
    protected $_collections = array (
  'Credentials' => 'Credential',
);

  protected $_service = "identity";
  protected $_method = "authenticate";
  protected $_response = "AuthenticationResponse";
  public $Credentials;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getCredentials() { return $this->Credentials; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setCredentials(array $a) { $this->Credentials = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultExternalAuthenticationRequest
*/
class AddCredentialsResponse extends NextgenObject {
  

  

  public function __construct() {
  }

  

  
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultAddCredentialsRequest
*/
class AddCredentialsRequest extends NextgenRequest {
    protected $_collections = array (
  'Credentials' => 'Credential',
);

  protected $_service = "identity";
  protected $_method = "addCredentials";
  protected $_response = "AddCredentialsResponse";
  public $Identity;
  public $Credentials;

  public function __construct() {
  }

  public function getIdentity() { return $this->Identity; }

  public function getCredentials() { return $this->Credentials; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }

  public function setCredentials(array $a) { $this->Credentials = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultAddIdentityAttributesResponse
*/
class AddIdentityAttributesResponse extends NextgenObject {
    protected $_collections = array (
  'Attributes' => 'Attribute',
);

  public $Attributes;
  public $Identity;

  public function __construct() {
  }

  public function getAttributes() { return $this->Attributes; }

  public function getIdentity() { return $this->Identity; }

  public function setAttributes(array $a) { $this->Attributes = $a; return $this; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultAddIdentityAttributesRequest
*/
class AddIdentityAttributesRequest extends NextgenRequest {
    protected $_collections = array (
  'Attributes' => 'Attribute',
);

  protected $_service = "identity";
  protected $_method = "addIdentityAttributes";
  protected $_response = "AddIdentityAttributesResponse";
  public $Attributes;
  public $Identity;

  public function __construct() {
  }

  public function getAttributes() { return $this->Attributes; }

  public function getIdentity() { return $this->Identity; }

  public function setAttributes(array $a) { $this->Attributes = $a; return $this; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultAddIdentityAttributesRequest
*/
class ChangeCredentialResponse extends NextgenObject {
  

  

  public function __construct() {
  }

  

  
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultChangeCredentialRequest
*/
class ChangeCredentialRequest extends NextgenRequest {
  

  protected $_service = "identity";
  protected $_method = "changeCredential";
  protected $_response = "ChangeCredentialResponse";
  public $Identity;
  public $AuthenticationCredential;
  public $ChangedCredential;

  public function __construct() {
  }

  public function getIdentity() { return $this->Identity; }

  public function getAuthenticationCredential() { return $this->AuthenticationCredential; }

  public function getChangedCredential() { return $this->ChangedCredential; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }

  public function setAuthenticationCredential(Credential $a) { $this->AuthenticationCredential = $a; return $this; }

  public function setChangedCredential(Credential $a) { $this->ChangedCredential = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultCreateIdentityResponse
*/
class CreateIdentityResponse extends NextgenObject {
  

  public $Identity;

  public function __construct($Identity = NULL) {
    $this->Identity = $Identity;
  }

  public function getIdentity() { return $this->Identity; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultCreateIdentityRequest
*/
class CreateIdentityRequest extends NextgenRequest {
    protected $_collections = array (
  'Attributes' => 'Attribute',
  'Credentials' => 'Credential',
);

  protected $_service = "identity";
  protected $_method = "createIdentity";
  protected $_response = "CreateIdentityResponse";
  public $Attributes;
  public $Credentials;

  public function __construct() {
  }

  public function getAttributes() { return $this->Attributes; }

  public function getCredentials() { return $this->Credentials; }

  public function setAttributes(array $a) { $this->Attributes = $a; return $this; }

  public function setCredentials(array $a) { $this->Credentials = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultCreateIdentityRequest
*/
class ForgottenCredentialResponse extends NextgenObject {
  

  

  public function __construct() {
  }

  

  
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultForgottenCredentialRequest
*/
class ForgottenCredentialRequest extends NextgenRequest {
    protected $_collections = array (
  'Attributes' => 'Attribute',
);

  protected $_service = "identity";
  protected $_method = "forgottenCredential";
  protected $_response = "ForgottenCredentialResponse";
  public $Attributes;
  public $CredentialName;

  public function __construct() {
  }

  public function getAttributes() { return $this->Attributes; }

  public function getCredentialName() { return $this->CredentialName; }

  public function setAttributes(array $a) { $this->Attributes = $a; return $this; }

  public function setCredentialName($a) { $this->CredentialName = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultGetAuthenticationChallengeResponse
*/
class GetAuthenticationChallengeResponse extends NextgenObject {
  

  public $Challenge;

  public function __construct($Challenge = NULL) {
    $this->Challenge = $Challenge;
  }

  public function getChallenge() { return $this->Challenge; }

  public function setChallenge(PartialCredentialChallenge $a) { $this->Challenge = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultPartialCredentialChallenge
*/
class PartialCredentialChallenge extends NextgenObject {
  

  public $CredentialName;
  public $ChallengeID;
  public $CharacterIndexes;

  public function __construct() {
  }

  public function getCredentialName() { return $this->CredentialName; }

  public function getChallengeID() { return $this->ChallengeID; }

  public function getCharacterIndexes() { return $this->CharacterIndexes; }

  public function setCredentialName($a) { $this->CredentialName = $a; return $this; }

  public function setChallengeID($a) { $this->ChallengeID = $a; return $this; }

  public function setCharacterIndexes(array $a) { $this->CharacterIndexes = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultGetAuthenticationChallengeRequest
*/
class GetAuthenticationChallengeRequest extends NextgenRequest {
  

  protected $_service = "identity";
  protected $_method = "getAuthenticationChallenge";
  protected $_response = "GetAuthenticationChallengeResponse";
  public $Identity;

  public function __construct($Identity = NULL) {
    $this->Identity = $Identity;
  }

  public function getIdentity() { return $this->Identity; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultGetIdentityDetailsResponse
*/
class GetIdentityDetailsResponse extends NextgenObject {
    protected $_collections = array (
  'Attributes' => 'Attribute',
);

  public $Attributes;
  public $Identity;
  public $IdentityStatus;
  public $AuthenticationLock;
  public $SenderName;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;

  public function __construct() {
  }

  public function getAttributes() { return $this->Attributes; }

  public function getIdentity() { return $this->Identity; }

  public function getIdentityStatus() { return $this->IdentityStatus; }

  public function getAuthenticationLock() { return $this->AuthenticationLock; }

  public function getSenderName() { return $this->SenderName; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function setAttributes(array $a) { $this->Attributes = $a; return $this; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }

  public function setIdentityStatus($a) { $this->IdentityStatus = $a; return $this; }

  public function setAuthenticationLock(AuthenticationLock $a) { $this->AuthenticationLock = $a; return $this; }

  public function setSenderName($a) { $this->SenderName = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultAuthenticationLock
*/
class AuthenticationLock extends NextgenObject {
  

  public $LockedTime;
  public $LockDurationMillis;

  public function __construct() {
  }

  public function getLockedTime() { return $this->LockedTime; }

  public function getLockDurationMillis() { return $this->LockDurationMillis; }

  public function setLockedTime(Date $a) { $this->LockedTime = $a; return $this; }

  public function setLockDurationMillis($a) { $this->LockDurationMillis = $a; return $this; }
}

/*
    Equivalent to java.util.Date
*/
class Date extends NextgenObject {
  

  public $Date;
  public $Hours;
  public $Minutes;
  public $Month;
  public $Seconds;
  public $Time;
  public $Year;
  public $Day;
  public $TimezoneOffset;

  public function __construct() {
  }

  public function getDate() { return $this->Date; }

  public function getHours() { return $this->Hours; }

  public function getMinutes() { return $this->Minutes; }

  public function getMonth() { return $this->Month; }

  public function getSeconds() { return $this->Seconds; }

  public function getTime() { return $this->Time; }

  public function getYear() { return $this->Year; }

  public function getDay() { return $this->Day; }

  public function getTimezoneOffset() { return $this->TimezoneOffset; }

  public function setDate($a) { $this->Date = $a; return $this; }

  public function setHours($a) { $this->Hours = $a; return $this; }

  public function setMinutes($a) { $this->Minutes = $a; return $this; }

  public function setMonth($a) { $this->Month = $a; return $this; }

  public function setSeconds($a) { $this->Seconds = $a; return $this; }

  public function setTime($a) { $this->Time = $a; return $this; }

  public function setYear($a) { $this->Year = $a; return $this; }

  public function setDay($a) { $this->Day = $a; return $this; }

  public function setTimezoneOffset($a) { $this->TimezoneOffset = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultGetIdentityDetailsRequest
*/
class GetIdentityDetailsRequest extends NextgenRequest {
  

  protected $_service = "identity";
  protected $_method = "getIdentityDetails";
  protected $_response = "GetIdentityDetailsResponse";
  public $Identity;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getIdentity() { return $this->Identity; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultGetSAMLForAuthenticationTokenResponse
*/
class GetSAMLForAuthenticationTokenResponse extends NextgenObject {
  

  public $SamlCertificate;

  public function __construct() {
  }

  public function getSamlCertificate() { return $this->SamlCertificate; }

  public function setSamlCertificate($a) { $this->SamlCertificate = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultGetSAMLForAuthenticationTokenRequest
*/
class GetSAMLForAuthenticationTokenRequest extends NextgenRequest {
  

  protected $_service = "identity";
  protected $_method = "getSamlForAuthenticationToken";
  protected $_response = "GetSAMLForAuthenticationTokenResponse";
  public $AuthenticationToken;

  public function __construct() {
  }

  public function getAuthenticationToken() { return $this->AuthenticationToken; }

  public function setAuthenticationToken($a) { $this->AuthenticationToken = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultGetSAMLForUserIDResponse
*/
class GetSAMLForUserIDResponse extends NextgenObject {
  

  public $SamlCertificate;

  public function __construct() {
  }

  public function getSamlCertificate() { return $this->SamlCertificate; }

  public function setSamlCertificate($a) { $this->SamlCertificate = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultGetSAMLForUserIDRequest
*/
class GetSAMLForUserIDRequest extends NextgenRequest {
  

  protected $_service = "identity";
  protected $_method = "getSamlForUserId";
  protected $_response = "GetSAMLForUserIDResponse";
  public $UserId;
  public $NameValues;

  public function __construct() {
  }

  public function getUserId() { return $this->UserId; }

  public function getNameValues() { return $this->NameValues; }

  public function setUserId($a) { $this->UserId = $a; return $this; }

  public function setNameValues($a) { $this->NameValues = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultGetOneTimeTokenResponse
*/
class GetOneTimeTokenResponse extends NextgenObject {
  

  public $CreationTime;
  public $OneTimeToken;
  public $ExpiryTime;

  public function __construct() {
  }

  public function getCreationTime() { return $this->CreationTime; }

  public function getOneTimeToken() { return $this->OneTimeToken; }

  public function getExpiryTime() { return $this->ExpiryTime; }

  public function setCreationTime($a) { $this->CreationTime = $a; return $this; }

  public function setOneTimeToken(OneTimeToken $a) { $this->OneTimeToken = $a; return $this; }

  public function setExpiryTime($a) { $this->ExpiryTime = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultOneTimeToken
*/
class OneTimeToken extends NextgenObject {
  

  public $Token;

  public function __construct($Token = NULL) {
    $this->Token = $Token;
  }

  public function getToken() { return $this->Token; }

  public function setToken($a) { $this->Token = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultGetOneTimeTokenRequest
*/
class GetOneTimeTokenRequest extends NextgenRequest {
  

  protected $_service = "identity";
  protected $_method = "getOneTimeToken";
  protected $_response = "GetOneTimeTokenResponse";
  public $Identity;

  public function __construct($Identity = NULL) {
    $this->Identity = $Identity;
  }

  public function getIdentity() { return $this->Identity; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultGetOneTimeTokenRequest
*/
class ModifyIdentityAttributeResponse extends NextgenObject {
  

  

  public function __construct() {
  }

  

  
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultModifyIdentityAttributeRequest
*/
class ModifyIdentityAttributeRequest extends NextgenRequest {
  

  protected $_service = "identity";
  protected $_method = "modifyIdentityAttribute";
  protected $_response = "ModifyIdentityAttributeResponse";
  public $Attribute;
  public $Identity;

  public function __construct() {
  }

  public function getAttribute() { return $this->Attribute; }

  public function getIdentity() { return $this->Identity; }

  public function setAttribute(Attribute $a) { $this->Attribute = $a; return $this; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultModifyIdentityAttributeRequest
*/
class ModifyIdentityStatusResponse extends NextgenObject {
  

  

  public function __construct() {
  }

  

  
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultModifyIdentityStatusRequest
*/
class ModifyIdentityStatusRequest extends NextgenRequest {
  

  protected $_service = "identity";
  protected $_method = "modifyIdentityStatus";
  protected $_response = "ModifyIdentityStatusResponse";
  public $Identity;
  public $IdentityStatus;

  public function __construct() {
  }

  public function getIdentity() { return $this->Identity; }

  public function getIdentityStatus() { return $this->IdentityStatus; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }

  public function setIdentityStatus($a) { $this->IdentityStatus = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultModifyIdentityStatusRequest
*/
class ResetCredentialResponse extends NextgenObject {
  

  

  public function __construct() {
  }

  

  
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultResetCredentialRequest
*/
class ResetCredentialRequest extends NextgenRequest {
  

  protected $_service = "identity";
  protected $_method = "resetCredential";
  protected $_response = "ResetCredentialResponse";
  public $Language;
  public $OneTimeToken;
  public $Credential;

  public function __construct() {
  }

  public function getLanguage() { return $this->Language; }

  public function getOneTimeToken() { return $this->OneTimeToken; }

  public function getCredential() { return $this->Credential; }

  public function setLanguage($a) { $this->Language = $a; return $this; }

  public function setOneTimeToken(OneTimeToken $a) { $this->OneTimeToken = $a; return $this; }

  public function setCredential(Credential $a) { $this->Credential = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultSearchIdentityResponse
*/
class SearchIdentityResponse extends NextgenObject {
    protected $_collections = array (
  'Identities' => 'Identity',
);

  public $Identities;

  public function __construct() {
  }

  public function getIdentities() { return $this->Identities; }

  public function setIdentities(array $a) { $this->Identities = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultSearchIdentityRequest
*/
class SearchIdentityRequest extends NextgenRequest {
    protected $_collections = array (
  'Attributes' => 'Attribute',
);

  protected $_service = "identity";
  protected $_method = "searchIdentity";
  protected $_response = "SearchIdentityResponse";
  public $Attributes;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getAttributes() { return $this->Attributes; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setAttributes(array $a) { $this->Attributes = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultVerifyAuthenticationTokenResponse
*/
class VerifyAuthenticationTokenResponse extends NextgenObject {
  

  public $Identity;
  public $AuthenticationTime;
  public $CredentialsUsed;
  public $SenderName;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;

  public function __construct() {
  }

  public function getIdentity() { return $this->Identity; }

  public function getAuthenticationTime() { return $this->AuthenticationTime; }

  public function getCredentialsUsed() { return $this->CredentialsUsed; }

  public function getSenderName() { return $this->SenderName; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }

  public function setAuthenticationTime($a) { $this->AuthenticationTime = $a; return $this; }

  public function setCredentialsUsed(array $a) { $this->CredentialsUsed = $a; return $this; }

  public function setSenderName($a) { $this->SenderName = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultVerifyAuthenticationTokenRequest
*/
class VerifyAuthenticationTokenRequest extends NextgenRequest {
  

  protected $_service = "identity";
  protected $_method = "verifyAuthenticationToken";
  protected $_response = "VerifyAuthenticationTokenResponse";
  public $AuthenticationToken;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getAuthenticationToken() { return $this->AuthenticationToken; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setAuthenticationToken(AuthenticationToken $a) { $this->AuthenticationToken = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultVerifyOneTimeTokenResponse
*/
class VerifyOneTimeTokenResponse extends NextgenObject {
  

  public $Identity;

  public function __construct($Identity = NULL) {
    $this->Identity = $Identity;
  }

  public function getIdentity() { return $this->Identity; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultVerifyOneTimeTokenRequest
*/
class VerifyOneTimeTokenRequest extends NextgenRequest {
  

  protected $_service = "identity";
  protected $_method = "verifyOneTimeToken";
  protected $_response = "VerifyOneTimeTokenResponse";
  public $OneTimeToken;

  public function __construct($OneTimeToken = NULL) {
    $this->OneTimeToken = $OneTimeToken;
  }

  public function getOneTimeToken() { return $this->OneTimeToken; }

  public function setOneTimeToken(OneTimeToken $a) { $this->OneTimeToken = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultConfirmIdentityReservationResponse
*/
class ConfirmIdentityReservationResponse extends NextgenObject {
  

  public $SenderName;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;

  public function __construct() {
  }

  public function getSenderName() { return $this->SenderName; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function setSenderName($a) { $this->SenderName = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultConfirmIdentityReservationRequest
*/
class ConfirmIdentityReservationRequest extends NextgenRequest {
  

  protected $_service = "identity";
  protected $_method = "confirmIdentityReservation";
  protected $_response = "ConfirmIdentityReservationResponse";
  public $Identity;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct($Identity = NULL) {
    $this->Identity = $Identity;
  }

  public function getIdentity() { return $this->Identity; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultReserveIdentityResponse
*/
class ReserveIdentityResponse extends NextgenObject {
  

  public $Identity;
  public $ReservedTillTime;
  public $SenderName;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;

  public function __construct($Identity = NULL, $ReservedTillTime = NULL) {
    $this->Identity = $Identity;
    $this->ReservedTillTime = $ReservedTillTime;
  }

  public function getIdentity() { return $this->Identity; }

  public function getReservedTillTime() { return $this->ReservedTillTime; }

  public function getSenderName() { return $this->SenderName; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }

  public function setReservedTillTime($a) { $this->ReservedTillTime = $a; return $this; }

  public function setSenderName($a) { $this->SenderName = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultReserveIdentityRequest
*/
class ReserveIdentityRequest extends NextgenRequest {
    protected $_collections = array (
  'Attributes' => 'Attribute',
  'Credentials' => 'Credential',
);

  protected $_service = "identity";
  protected $_method = "reserveIdentity";
  protected $_response = "ReserveIdentityResponse";
  public $Attributes;
  public $Credentials;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct($Attributes = NULL, $Credentials = NULL) {
    $this->Attributes = $Attributes;
    $this->Credentials = $Credentials;
  }

  public function getAttributes() { return $this->Attributes; }

  public function getCredentials() { return $this->Credentials; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setAttributes(array $a) { $this->Attributes = $a; return $this; }

  public function setCredentials(array $a) { $this->Credentials = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultUnreserveIdentityResponse
*/
class UnreserveIdentityResponse extends NextgenObject {
  

  public $SenderName;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;

  public function __construct() {
  }

  public function getSenderName() { return $this->SenderName; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function setSenderName($a) { $this->SenderName = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultUnreserveIdentityRequest
*/
class UnreserveIdentityRequest extends NextgenRequest {
  

  protected $_service = "identity";
  protected $_method = "unreserveIdentity";
  protected $_response = "UnreserveIdentityResponse";
  public $Identity;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct($Identity = NULL) {
    $this->Identity = $Identity;
  }

  public function getIdentity() { return $this->Identity; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultVerifySAMLAuthenticationResponse
*/
class VerifySAMLAuthenticationResponse extends NextgenObject {
    protected $_collections = array (
  'Attributes' => 'Attribute',
);

  public $Attributes;
  public $Subject;
  public $AuthenticationTime;
  public $Issuer;
  public $IssueTime;
  public $SenderName;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;

  public function __construct($Issuer = NULL, $Subject = NULL, $IssueTime = NULL, $AuthenticationTime = NULL, $Attributes = NULL) {
    $this->Issuer = $Issuer;
    $this->Subject = $Subject;
    $this->IssueTime = $IssueTime;
    $this->AuthenticationTime = $AuthenticationTime;
    $this->Attributes = $Attributes;
  }

  public function getAttributes() { return $this->Attributes; }

  public function getSubject() { return $this->Subject; }

  public function getAuthenticationTime() { return $this->AuthenticationTime; }

  public function getIssuer() { return $this->Issuer; }

  public function getIssueTime() { return $this->IssueTime; }

  public function getSenderName() { return $this->SenderName; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function setAttributes(array $a) { $this->Attributes = $a; return $this; }

  public function setSubject(Name $a) { $this->Subject = $a; return $this; }

  public function setAuthenticationTime(Date $a) { $this->AuthenticationTime = $a; return $this; }

  public function setIssuer(Name $a) { $this->Issuer = $a; return $this; }

  public function setIssueTime(Date $a) { $this->IssueTime = $a; return $this; }

  public function setSenderName($a) { $this->SenderName = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultName
*/
class Name extends NextgenObject {
  

  public $Value;
  public $Format;
  public $Qualifier;

  public function __construct($Value = NULL, $Qualifier = NULL, $Format = NULL) {
    $this->Value = $Value;
    $this->Qualifier = $Qualifier;
    $this->Format = $Format;
  }

  public function getValue() { return $this->Value; }

  public function getFormat() { return $this->Format; }

  public function getQualifier() { return $this->Qualifier; }

  public function setValue($a) { $this->Value = $a; return $this; }

  public function setFormat($a) { $this->Format = $a; return $this; }

  public function setQualifier($a) { $this->Qualifier = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultVerifySAMLAuthenticationRequest
*/
class VerifySAMLAuthenticationRequest extends NextgenRequest {
  

  protected $_service = "identity";
  protected $_method = "verifySAMLAuthentication";
  protected $_response = "VerifySAMLAuthenticationResponse";
  public $SAMLAuthentication;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct($Saml = NULL) {
    $this->Saml = $Saml;
  }

  public function getSAMLAuthentication() { return $this->SAMLAuthentication; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setSAMLAuthentication($a) { $this->SAMLAuthentication = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultRemoveIdentityResponse
*/
class RemoveIdentityResponse extends NextgenObject {
  

  public $Identity;
  public $SenderName;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;

  public function __construct() {
  }

  public function getIdentity() { return $this->Identity; }

  public function getSenderName() { return $this->SenderName; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }

  public function setSenderName($a) { $this->SenderName = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.identity.api.model.DefaultRemoveIdentityRequest
*/
class RemoveIdentityRequest extends NextgenRequest {
  

  protected $_service = "identity";
  protected $_method = "removeIdentity";
  protected $_response = "RemoveIdentityResponse";
  public $Identity;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getIdentity() { return $this->Identity; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.session.api.model.DefaultGetSessionResponse
*/
class GetSessionResponse extends NextgenObject {
  

  public $Session;

  public function __construct($Session = NULL) {
    $this->Session = $Session;
  }

  public function getSession() { return $this->Session; }

  public function setSession(Session $a) { $this->Session = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.session.api.model.DefaultSession
*/
class Session extends NextgenObject {
    protected $_collections = array (
  'SessionAttributes' => 'SessionAttribute',
);

  public $StartTime;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $Identity;
  public $ExpiryTime;
  public $SessionAttributes;

  public function __construct() {
  }

  public function getStartTime() { return $this->StartTime; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getIdentity() { return $this->Identity; }

  public function getExpiryTime() { return $this->ExpiryTime; }

  public function getSessionAttributes() { return $this->SessionAttributes; }

  public function setStartTime($a) { $this->StartTime = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }

  public function setExpiryTime($a) { $this->ExpiryTime = $a; return $this; }

  public function setSessionAttributes(array $a) { $this->SessionAttributes = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.session.api.model.DefaultSessionAttribute
*/
class SessionAttribute extends NextgenObject {
  

  public $Name;
  public $Value;

  public function __construct($Name = NULL, $Value = NULL) {
    $this->Name = $Name;
    $this->Value = $Value;
  }

  public function getName() { return $this->Name; }

  public function getValue() { return $this->Value; }

  public function setName($a) { $this->Name = $a; return $this; }

  public function setValue($a) { $this->Value = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.session.api.model.DefaultGetSessionRequest
*/
class GetSessionRequest extends NextgenRequest {
  

  protected $_service = "session";
  protected $_method = "getSession";
  protected $_response = "GetSessionResponse";
  public $SessionKey;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getSessionKey() { return $this->SessionKey; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.session.api.model.DefaultCreateSessionResponse
*/
class CreateSessionResponse extends NextgenObject {
  

  public $Session;

  public function __construct($Session = NULL) {
    $this->Session = $Session;
  }

  public function getSession() { return $this->Session; }

  public function setSession(Session $a) { $this->Session = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.session.api.model.DefaultCreateSessionRequest
*/
class CreateSessionRequest extends NextgenRequest {
    protected $_collections = array (
  'AuthenticationTokens' => 'AuthenticationToken',
);

  protected $_service = "session";
  protected $_method = "createSession";
  protected $_response = "CreateSessionResponse";
  public $AuthenticationTokens;
  public $TradingAccountID;
  public $TerminateExistingSession;
  public $IPAddress;
  public $DeviceID;
  public $DeviceFingerprint;
  public $GatewayServiceID;
  public $GatewayIPAddress;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getAuthenticationTokens() { return $this->AuthenticationTokens; }

  public function getTradingAccountID() { return $this->TradingAccountID; }

  public function getTerminateExistingSession() { return $this->TerminateExistingSession; }

  public function getIPAddress() { return $this->IPAddress; }

  public function getDeviceID() { return $this->DeviceID; }

  public function getDeviceFingerprint() { return $this->DeviceFingerprint; }

  public function getGatewayServiceID() { return $this->GatewayServiceID; }

  public function getGatewayIPAddress() { return $this->GatewayIPAddress; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setAuthenticationTokens(array $a) { $this->AuthenticationTokens = $a; return $this; }

  public function setTradingAccountID($a) { $this->TradingAccountID = $a; return $this; }

  public function setTerminateExistingSession($a) { $this->TerminateExistingSession = $a; return $this; }

  public function setIPAddress($a) { $this->IPAddress = $a; return $this; }

  public function setDeviceID($a) { $this->DeviceID = $a; return $this; }

  public function setDeviceFingerprint($a) { $this->DeviceFingerprint = $a; return $this; }

  public function setGatewayServiceID($a) { $this->GatewayServiceID = $a; return $this; }

  public function setGatewayIPAddress($a) { $this->GatewayIPAddress = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.session.api.model.DefaultExtendSessionResponse
*/
class ExtendSessionResponse extends NextgenObject {
  

  public $Session;

  public function __construct($Session = NULL) {
    $this->Session = $Session;
  }

  public function getSession() { return $this->Session; }

  public function setSession(Session $a) { $this->Session = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.session.api.model.DefaultExtendSessionRequest
*/
class ExtendSessionRequest extends NextgenRequest {
  

  protected $_service = "session";
  protected $_method = "extendSession";
  protected $_response = "ExtendSessionResponse";
  public $SessionKey;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getSessionKey() { return $this->SessionKey; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.session.api.model.DefaultGetAllActiveSessionsResponse
*/
class GetAllActiveSessionsResponse extends NextgenObject {
    protected $_collections = array (
  'Sessions' => 'Session',
);

  public $Sessions;

  public function __construct() {
  }

  public function getSessions() { return $this->Sessions; }

  public function setSessions(array $a) { $this->Sessions = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.session.api.model.DefaultGetAllActiveSessionsRequest
*/
class GetAllActiveSessionsRequest extends NextgenRequest {
  

  protected $_service = "session";
  protected $_method = "getAllActiveSessions";
  protected $_response = "GetAllActiveSessionsResponse";
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.session.api.model.DefaultTerminateSessionResponse
*/
class TerminateSessionResponse extends NextgenObject {
  

  public $Session;

  public function __construct() {
  }

  public function getSession() { return $this->Session; }

  public function setSession(Session $a) { $this->Session = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.session.api.model.DefaultTerminateSessionRequest
*/
class TerminateSessionRequest extends NextgenRequest {
  

  protected $_service = "session";
  protected $_method = "terminateSession";
  protected $_response = "TerminateSessionResponse";
  public $SessionKey;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getSessionKey() { return $this->SessionKey; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.session.api.model.DefaultSetSessionAttributesResponse
*/
class SetSessionAttributesResponse extends NextgenObject {
  

  public $Session;

  public function __construct($Session = NULL) {
    $this->Session = $Session;
  }

  public function getSession() { return $this->Session; }

  public function setSession(Session $a) { $this->Session = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.session.api.model.DefaultSetSessionAttributesRequest
*/
class SetSessionAttributesRequest extends NextgenRequest {
    protected $_collections = array (
  'SessionAttributes' => 'SessionAttribute',
);

  protected $_service = "session";
  protected $_method = "setSessionAttributes";
  protected $_response = "SetSessionAttributesResponse";
  public $SessionKey;
  public $SessionAttributes;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getSessionKey() { return $this->SessionKey; }

  public function getSessionAttributes() { return $this->SessionAttributes; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setSessionAttributes(array $a) { $this->SessionAttributes = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.session.api.model.DefaultGetSessionTransferTokenResponse
*/
class GetSessionTransferTokenResponse extends NextgenObject {
  

  public $SessionTransferToken;

  public function __construct($SessionTransferToken = NULL) {
    $this->SessionTransferToken = $SessionTransferToken;
  }

  public function getSessionTransferToken() { return $this->SessionTransferToken; }

  public function setSessionTransferToken(SessionTransferToken $a) { $this->SessionTransferToken = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.session.api.model.DefaultSessionTransferToken
*/
class SessionTransferToken extends NextgenObject {
  

  public $Token;

  public function __construct() {
  }

  public function getToken() { return $this->Token; }

  public function setToken($a) { $this->Token = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.session.api.model.DefaultGetSessionTransferTokenRequest
*/
class GetSessionTransferTokenRequest extends NextgenRequest {
  

  protected $_service = "session";
  protected $_method = "getSessionTransferToken";
  protected $_response = "GetSessionTransferTokenResponse";
  public $SessionKey;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getSessionKey() { return $this->SessionKey; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.session.api.model.DefaultVerifySessionTransferTokenResponse
*/
class VerifySessionTransferTokenResponse extends NextgenObject {
  

  public $Session;

  public function __construct() {
  }

  public function getSession() { return $this->Session; }

  public function setSession(Session $a) { $this->Session = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.session.api.model.DefaultVerifySessionTransferTokenRequest
*/
class VerifySessionTransferTokenRequest extends NextgenRequest {
  

  protected $_service = "session";
  protected $_method = "verifySessionTransferToken";
  protected $_response = "VerifySessionTransferTokenResponse";
  public $SessionTransferToken;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getSessionTransferToken() { return $this->SessionTransferToken; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setSessionTransferToken(SessionTransferToken $a) { $this->SessionTransferToken = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.session.api.model.DefaultGetSessionHistoryResponse
*/
class GetSessionHistoryResponse extends NextgenObject {
    protected $_collections = array (
  'Sessions' => 'Session',
);

  public $Sessions;
  public $SenderName;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;

  public function __construct() {
  }

  public function getSessions() { return $this->Sessions; }

  public function getSenderName() { return $this->SenderName; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function setSessions(array $a) { $this->Sessions = $a; return $this; }

  public function setSenderName($a) { $this->SenderName = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.session.api.model.DefaultGetSessionHistoryRequest
*/
class GetSessionHistoryRequest extends NextgenRequest {
    protected $_collections = array (
  'SessionAttributes' => 'SessionAttribute',
);

  protected $_service = "session";
  protected $_method = "getSessionHistory";
  protected $_response = "GetSessionHistoryResponse";
  public $Identity;
  public $SessionAttributes;
  public $FromTime;
  public $ToTime;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getIdentity() { return $this->Identity; }

  public function getSessionAttributes() { return $this->SessionAttributes; }

  public function getFromTime() { return $this->FromTime; }

  public function getToTime() { return $this->ToTime; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }

  public function setSessionAttributes(array $a) { $this->SessionAttributes = $a; return $this; }

  public function setFromTime(Date $a) { $this->FromTime = $a; return $this; }

  public function setToTime(Date $a) { $this->ToTime = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.clientverification.api.model.DefaultGetFullPostalAddressResponse
*/
class GetFullPostalAddressResponse extends NextgenObject {
  

  public $FullAddress;
  public $SenderName;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;

  public function __construct() {
  }

  public function getFullAddress() { return $this->FullAddress; }

  public function getSenderName() { return $this->SenderName; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function setFullAddress(Address2 $a) { $this->FullAddress = $a; return $this; }

  public function setSenderName($a) { $this->SenderName = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.clientverification.api.model.DefaultAddress
*/
class Address2 extends NextgenObject {
  

  public $State;
  public $Country;
  public $AddressLines;
  public $Town;
  public $County;
  public $Postcode;
  public $StreetName;
  public $StreetNumber;
  public $FlatNumber;

  public function __construct() {
  }

  public function getState() { return $this->State; }

  public function getCountry() { return $this->Country; }

  public function getAddressLines() { return $this->AddressLines; }

  public function getTown() { return $this->Town; }

  public function getCounty() { return $this->County; }

  public function getPostcode() { return $this->Postcode; }

  public function getStreetName() { return $this->StreetName; }

  public function getStreetNumber() { return $this->StreetNumber; }

  public function getFlatNumber() { return $this->FlatNumber; }

  public function setState($a) { $this->State = $a; return $this; }

  public function setCountry($a) { $this->Country = $a; return $this; }

  public function setAddressLines(array $a) { $this->AddressLines = $a; return $this; }

  public function setTown($a) { $this->Town = $a; return $this; }

  public function setCounty($a) { $this->County = $a; return $this; }

  public function setPostcode($a) { $this->Postcode = $a; return $this; }

  public function setStreetName($a) { $this->StreetName = $a; return $this; }

  public function setStreetNumber($a) { $this->StreetNumber = $a; return $this; }

  public function setFlatNumber($a) { $this->FlatNumber = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.clientverification.api.model.DefaultGetFullPostalAddressRequest
*/
class GetFullPostalAddressRequest extends NextgenRequest {
  

  protected $_service = "clientVerification";
  protected $_method = "getFullPostalAddress";
  protected $_response = "GetFullPostalAddressResponse";
  public $Id;
  public $Country;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getId() { return $this->Id; }

  public function getCountry() { return $this->Country; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setId($a) { $this->Id = $a; return $this; }

  public function setCountry($a) { $this->Country = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.clientverification.api.model.DefaultGetPostalAddressMatchesResponse
*/
class GetPostalAddressMatchesResponse extends NextgenObject {
    protected $_collections = array (
  'MatchingAddresses' => 'PostalAddressMatch',
);

  public $MatchingAddresses;
  public $SenderName;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;

  public function __construct() {
  }

  public function getMatchingAddresses() { return $this->MatchingAddresses; }

  public function getSenderName() { return $this->SenderName; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function setMatchingAddresses(array $a) { $this->MatchingAddresses = $a; return $this; }

  public function setSenderName($a) { $this->SenderName = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.clientverification.api.model.DefaultPostalAddressMatch
*/
class PostalAddressMatch extends NextgenObject {
  

  public $DisplayLine;
  public $AddressId;

  public function __construct() {
  }

  public function getDisplayLine() { return $this->DisplayLine; }

  public function getAddressId() { return $this->AddressId; }

  public function setDisplayLine($a) { $this->DisplayLine = $a; return $this; }

  public function setAddressId($a) { $this->AddressId = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.clientverification.api.model.DefaultGetPostalAddressMatchesRequest
*/
class GetPostalAddressMatchesRequest extends NextgenRequest {
  

  protected $_service = "clientVerification";
  protected $_method = "getPostalAddressMatches";
  protected $_response = "GetPostalAddressMatchesResponse";
  public $Country;
  public $SearchTerm;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getCountry() { return $this->Country; }

  public function getSearchTerm() { return $this->SearchTerm; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setCountry($a) { $this->Country = $a; return $this; }

  public function setSearchTerm($a) { $this->SearchTerm = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.clientverification.api.model.DefaultValidateBankAccountResponse
*/
class ValidateBankAccountResponse extends NextgenObject {
  

  public $BankAccount;
  public $Valid;
  public $ResponseCodes;
  public $IBAN;
  public $SenderName;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;

  public function __construct() {
  }

  public function getBankAccount() { return $this->BankAccount; }

  public function getValid() { return $this->Valid; }

  public function getResponseCodes() { return $this->ResponseCodes; }

  public function getIBAN() { return $this->IBAN; }

  public function getSenderName() { return $this->SenderName; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function setBankAccount(BankAccount $a) { $this->BankAccount = $a; return $this; }

  public function setValid($a) { $this->Valid = $a; return $this; }

  public function setResponseCodes(array $a) { $this->ResponseCodes = $a; return $this; }

  public function setIBAN($a) { $this->IBAN = $a; return $this; }

  public function setSenderName($a) { $this->SenderName = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.clientverification.api.model.DefaultBankAccount
*/
class BankAccount extends NextgenObject {
    protected $_collections = array (
  'BBANFields' => 'BBANField',
);

  public $IBAN;
  public $CountryCode;
  public $BBANFields;
  public $BIC;

  public function __construct() {
  }

  public function getIBAN() { return $this->IBAN; }

  public function getCountryCode() { return $this->CountryCode; }

  public function getBBANFields() { return $this->BBANFields; }

  public function getBIC() { return $this->BIC; }

  public function setIBAN($a) { $this->IBAN = $a; return $this; }

  public function setCountryCode($a) { $this->CountryCode = $a; return $this; }

  public function setBBANFields(array $a) { $this->BBANFields = $a; return $this; }

  public function setBIC($a) { $this->BIC = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.clientverification.api.model.DefaultBBANField
*/
class BBANField extends NextgenObject {
  

  public $Name;
  public $Value;
  public $MaximumLength;

  public function __construct() {
  }

  public function getName() { return $this->Name; }

  public function getValue() { return $this->Value; }

  public function getMaximumLength() { return $this->MaximumLength; }

  public function setName($a) { $this->Name = $a; return $this; }

  public function setValue($a) { $this->Value = $a; return $this; }

  public function setMaximumLength($a) { $this->MaximumLength = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.clientverification.api.model.DefaultValidateBankAccountRequest
*/
class ValidateBankAccountRequest extends NextgenRequest {
  

  protected $_service = "clientVerification";
  protected $_method = "validateBankAccount";
  protected $_response = "ValidateBankAccountResponse";
  public $BankAccount;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getBankAccount() { return $this->BankAccount; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setBankAccount(BankAccount $a) { $this->BankAccount = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.clientverification.api.model.DefaultVerifyBankAccountResponse
*/
class VerifyBankAccountResponse extends NextgenObject {
  

  public $IBAN;
  public $AccountExists;
  public $PersonalDetailsScore;
  public $AddressScore;
  public $SenderName;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;

  public function __construct() {
  }

  public function getIBAN() { return $this->IBAN; }

  public function getAccountExists() { return $this->AccountExists; }

  public function getPersonalDetailsScore() { return $this->PersonalDetailsScore; }

  public function getAddressScore() { return $this->AddressScore; }

  public function getSenderName() { return $this->SenderName; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function setIBAN($a) { $this->IBAN = $a; return $this; }

  public function setAccountExists($a) { $this->AccountExists = $a; return $this; }

  public function setPersonalDetailsScore($a) { $this->PersonalDetailsScore = $a; return $this; }

  public function setAddressScore($a) { $this->AddressScore = $a; return $this; }

  public function setSenderName($a) { $this->SenderName = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.clientverification.api.model.DefaultVerifyBankAccountRequest
*/
class VerifyBankAccountRequest extends NextgenRequest {
  

  protected $_service = "clientVerification";
  protected $_method = "verifyBankAccount";
  protected $_response = "VerifyBankAccountResponse";
  public $Address;
  public $BankAccount;
  public $FirstName;
  public $LastName;
  public $DateOfBirth;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getAddress() { return $this->Address; }

  public function getBankAccount() { return $this->BankAccount; }

  public function getFirstName() { return $this->FirstName; }

  public function getLastName() { return $this->LastName; }

  public function getDateOfBirth() { return $this->DateOfBirth; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setAddress(Address2 $a) { $this->Address = $a; return $this; }

  public function setBankAccount(BankAccount $a) { $this->BankAccount = $a; return $this; }

  public function setFirstName($a) { $this->FirstName = $a; return $this; }

  public function setLastName($a) { $this->LastName = $a; return $this; }

  public function setDateOfBirth(Date $a) { $this->DateOfBirth = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.clientverification.api.model.DefaultVerifyCustomerBankAccountResponse
*/
class VerifyCustomerBankAccountResponse extends NextgenObject {
  

  public $IBAN;
  public $AccountExists;
  public $PersonalDetailsScore;
  public $AddressScore;
  public $SenderName;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;

  public function __construct() {
  }

  public function getIBAN() { return $this->IBAN; }

  public function getAccountExists() { return $this->AccountExists; }

  public function getPersonalDetailsScore() { return $this->PersonalDetailsScore; }

  public function getAddressScore() { return $this->AddressScore; }

  public function getSenderName() { return $this->SenderName; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function setIBAN($a) { $this->IBAN = $a; return $this; }

  public function setAccountExists($a) { $this->AccountExists = $a; return $this; }

  public function setPersonalDetailsScore($a) { $this->PersonalDetailsScore = $a; return $this; }

  public function setAddressScore($a) { $this->AddressScore = $a; return $this; }

  public function setSenderName($a) { $this->SenderName = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.clientverification.api.model.DefaultVerifyCustomerBankAccountRequest
*/
class VerifyCustomerBankAccountRequest extends NextgenRequest {
  

  protected $_service = "clientVerification";
  protected $_method = "verifyCustomerBankAccount";
  protected $_response = "VerifyCustomerBankAccountResponse";
  public $BankAccount;
  public $PersonId;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getBankAccount() { return $this->BankAccount; }

  public function getPersonId() { return $this->PersonId; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setBankAccount(BankAccount $a) { $this->BankAccount = $a; return $this; }

  public function setPersonId($a) { $this->PersonId = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.clientverification.api.model.DefaultVerifyFullPostalAddressResponse
*/
class VerifyFullPostalAddressResponse extends NextgenObject {
  

  public $Address;
  public $SenderName;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;

  public function __construct() {
  }

  public function getAddress() { return $this->Address; }

  public function getSenderName() { return $this->SenderName; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function setAddress(Address2 $a) { $this->Address = $a; return $this; }

  public function setSenderName($a) { $this->SenderName = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.clientverification.api.model.DefaultVerifyFullPostalAddressRequest
*/
class VerifyFullPostalAddressRequest extends NextgenRequest {
  

  protected $_service = "clientVerification";
  protected $_method = "verifyFullPostalAddress";
  protected $_response = "VerifyFullPostalAddressResponse";
  public $Address;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getAddress() { return $this->Address; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setAddress(Address2 $a) { $this->Address = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.clientverification.api.model.DefaultGetBankAccountMetaDataResponse
*/
class GetBankAccountMetaDataResponse extends NextgenObject {
    protected $_collections = array (
  'BBANFields' => 'BBANField',
);

  public $BBANFields;
  public $SenderName;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;

  public function __construct() {
  }

  public function getBBANFields() { return $this->BBANFields; }

  public function getSenderName() { return $this->SenderName; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function setBBANFields(array $a) { $this->BBANFields = $a; return $this; }

  public function setSenderName($a) { $this->SenderName = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.clientverification.api.model.DefaultGetBankAccountMetaDataRequest
*/
class GetBankAccountMetaDataRequest extends NextgenRequest {
  

  protected $_service = "clientVerification";
  protected $_method = "getBankAccountMetaData";
  protected $_response = "GetBankAccountMetaDataResponse";
  public $CountryCode;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getCountryCode() { return $this->CountryCode; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setCountryCode($a) { $this->CountryCode = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.clientverification.api.model.DefaultAuthenticationResponse
*/
class AuthenticationResponse2 extends NextgenObject {
  

  public $Provider;
  public $Request;
  public $Reason;
  public $Pass;
  public $Report;
  public $Score;
  public $Warning;
  public $SenderName;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;

  public function __construct() {
  }

  public function getProvider() { return $this->Provider; }

  public function getRequest() { return $this->Request; }

  public function getReason() { return $this->Reason; }

  public function getPass() { return $this->Pass; }

  public function getReport() { return $this->Report; }

  public function getScore() { return $this->Score; }

  public function getWarning() { return $this->Warning; }

  public function getSenderName() { return $this->SenderName; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function setProvider($a) { $this->Provider = $a; return $this; }

  public function setRequest(AuthenticationRequest $a) { $this->Request = $a; return $this; }

  public function setReason($a) { $this->Reason = $a; return $this; }

  public function setPass($a) { $this->Pass = $a; return $this; }

  public function setReport($a) { $this->Report = $a; return $this; }

  public function setScore($a) { $this->Score = $a; return $this; }

  public function setWarning($a) { $this->Warning = $a; return $this; }

  public function setSenderName($a) { $this->SenderName = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.clientverification.api.model.DefaultAuthenticationRequest
*/
class AuthenticationRequest extends NextgenRequest {
    protected $_collections = array (
  'Addresses' => 'AuthenticationAddressWrapper',
  'Identifications' => 'Identification',
);

  protected $_service = "clientVerification";
  protected $_method = "authentication";
  protected $_response = "AuthenticationResponse2";
  public $Country;
  public $Generals;
  public $Addresses;
  public $Identifications;
  public $ClientReference;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getCountry() { return $this->Country; }

  public function getGenerals() { return $this->Generals; }

  public function getAddresses() { return $this->Addresses; }

  public function getIdentifications() { return $this->Identifications; }

  public function getClientReference() { return $this->ClientReference; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setCountry($a) { $this->Country = $a; return $this; }

  public function setGenerals(Generals $a) { $this->Generals = $a; return $this; }

  public function setAddresses(array $a) { $this->Addresses = $a; return $this; }

  public function setIdentifications(array $a) { $this->Identifications = $a; return $this; }

  public function setClientReference($a) { $this->ClientReference = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.clientverification.api.model.DefaultGenerals
*/
class Generals extends NextgenObject {
  

  public $Name;
  public $Surname;
  public $DateOfBirth;
  public $Gender;

  public function __construct() {
  }

  public function getName() { return $this->Name; }

  public function getSurname() { return $this->Surname; }

  public function getDateOfBirth() { return $this->DateOfBirth; }

  public function getGender() { return $this->Gender; }

  public function setName($a) { $this->Name = $a; return $this; }

  public function setSurname($a) { $this->Surname = $a; return $this; }

  public function setDateOfBirth(Date $a) { $this->DateOfBirth = $a; return $this; }

  public function setGender($a) { $this->Gender = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.clientverification.api.model.DefaultAuthenticationAddressWrapper
*/
class AuthenticationAddressWrapper extends NextgenObject {
  

  public $Address;
  public $AddressType;

  public function __construct() {
  }

  public function getAddress() { return $this->Address; }

  public function getAddressType() { return $this->AddressType; }

  public function setAddress(Address2 $a) { $this->Address = $a; return $this; }

  public function setAddressType($a) { $this->AddressType = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.clientverification.api.model.DefaultIdentification
*/
class Identification extends NextgenObject {
    protected $_collections = array (
  'AdditionalFields' => 'NameValuePair',
);

  public $Name;
  public $Type;
  public $Number;
  public $Issuer;
  public $StartDate;
  public $EndDate;
  public $SecondaryNumber;
  public $AdditionalFields;

  public function __construct() {
  }

  public function getName() { return $this->Name; }

  public function getType() { return $this->Type; }

  public function getNumber() { return $this->Number; }

  public function getIssuer() { return $this->Issuer; }

  public function getStartDate() { return $this->StartDate; }

  public function getEndDate() { return $this->EndDate; }

  public function getSecondaryNumber() { return $this->SecondaryNumber; }

  public function getAdditionalFields() { return $this->AdditionalFields; }

  public function setName($a) { $this->Name = $a; return $this; }

  public function setType($a) { $this->Type = $a; return $this; }

  public function setNumber($a) { $this->Number = $a; return $this; }

  public function setIssuer($a) { $this->Issuer = $a; return $this; }

  public function setStartDate(Date $a) { $this->StartDate = $a; return $this; }

  public function setEndDate(Date $a) { $this->EndDate = $a; return $this; }

  public function setSecondaryNumber($a) { $this->SecondaryNumber = $a; return $this; }

  public function setAdditionalFields(array $a) { $this->AdditionalFields = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.clientverification.api.model.DefaultNameValuePair
*/
class NameValuePair extends NextgenObject {
  

  public $Name;
  public $Value;

  public function __construct() {
  }

  public function getName() { return $this->Name; }

  public function getValue() { return $this->Value; }

  public function setName($a) { $this->Name = $a; return $this; }

  public function setValue($a) { $this->Value = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.clientverification.api.model.DefaultSanctionResponse
*/
class SanctionResponse extends NextgenObject {
  

  public $Provider;
  public $Request;
  public $Reason;
  public $Pass;
  public $Report;
  public $Score;
  public $Warning;
  public $SenderName;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;

  public function __construct() {
  }

  public function getProvider() { return $this->Provider; }

  public function getRequest() { return $this->Request; }

  public function getReason() { return $this->Reason; }

  public function getPass() { return $this->Pass; }

  public function getReport() { return $this->Report; }

  public function getScore() { return $this->Score; }

  public function getWarning() { return $this->Warning; }

  public function getSenderName() { return $this->SenderName; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function setProvider($a) { $this->Provider = $a; return $this; }

  public function setRequest(SanctionRequest $a) { $this->Request = $a; return $this; }

  public function setReason($a) { $this->Reason = $a; return $this; }

  public function setPass($a) { $this->Pass = $a; return $this; }

  public function setReport($a) { $this->Report = $a; return $this; }

  public function setScore($a) { $this->Score = $a; return $this; }

  public function setWarning($a) { $this->Warning = $a; return $this; }

  public function setSenderName($a) { $this->SenderName = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.clientverification.api.model.DefaultSanctionRequest
*/
class SanctionRequest extends NextgenRequest {
    protected $_collections = array (
  'Addresses' => 'AuthenticationAddressWrapper',
  'Identifications' => 'Identification',
);

  protected $_service = "clientVerification";
  protected $_method = "sanction";
  protected $_response = "SanctionResponse";
  public $Country;
  public $Generals;
  public $Addresses;
  public $Identifications;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getCountry() { return $this->Country; }

  public function getGenerals() { return $this->Generals; }

  public function getAddresses() { return $this->Addresses; }

  public function getIdentifications() { return $this->Identifications; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setCountry($a) { $this->Country = $a; return $this; }

  public function setGenerals(Generals $a) { $this->Generals = $a; return $this; }

  public function setAddresses(array $a) { $this->Addresses = $a; return $this; }

  public function setIdentifications(array $a) { $this->Identifications = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.registration.api.model.DefaultRegisterDemoCustomerResponse
*/
class RegisterDemoCustomerResponse extends NextgenObject {
  

  public $Identity;
  public $PersonId;
  public $CustomerId;
  public $TradingAccountId;

  public function __construct($Identity = NULL) {
    $this->Identity = $Identity;
  }

  public function getIdentity() { return $this->Identity; }

  public function getPersonId() { return $this->PersonId; }

  public function getCustomerId() { return $this->CustomerId; }

  public function getTradingAccountId() { return $this->TradingAccountId; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }

  public function setPersonId($a) { $this->PersonId = $a; return $this; }

  public function setCustomerId($a) { $this->CustomerId = $a; return $this; }

  public function setTradingAccountId($a) { $this->TradingAccountId = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.registration.api.model.DefaultRegisterDemoCustomerRequest
*/
class RegisterDemoCustomerRequest extends NextgenRequest {
  

  protected $_service = "registration";
  protected $_method = "registerDemoCustomer";
  protected $_response = "RegisterDemoCustomerResponse";
  public $Language;
  public $Country;
  public $Password;
  public $Currency;
  public $DeviceId;
  public $Identity;
  public $ReasonCode;
  public $EmailAddress;
  public $IpAddress;
  public $TenantTemplateCode;
  public $OptOut;
  public $PersonalDetails;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getLanguage() { return $this->Language; }

  public function getCountry() { return $this->Country; }

  public function getPassword() { return $this->Password; }

  public function getCurrency() { return $this->Currency; }

  public function getDeviceId() { return $this->DeviceId; }

  public function getIdentity() { return $this->Identity; }

  public function getReasonCode() { return $this->ReasonCode; }

  public function getEmailAddress() { return $this->EmailAddress; }

  public function getIpAddress() { return $this->IpAddress; }

  public function getTenantTemplateCode() { return $this->TenantTemplateCode; }

  public function getOptOut() { return $this->OptOut; }

  public function getPersonalDetails() { return $this->PersonalDetails; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setLanguage($a) { $this->Language = $a; return $this; }

  public function setCountry($a) { $this->Country = $a; return $this; }

  public function setPassword($a) { $this->Password = $a; return $this; }

  public function setCurrency($a) { $this->Currency = $a; return $this; }

  public function setDeviceId($a) { $this->DeviceId = $a; return $this; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }

  public function setReasonCode($a) { $this->ReasonCode = $a; return $this; }

  public function setEmailAddress($a) { $this->EmailAddress = $a; return $this; }

  public function setIpAddress($a) { $this->IpAddress = $a; return $this; }

  public function setTenantTemplateCode($a) { $this->TenantTemplateCode = $a; return $this; }

  public function setOptOut($a) { $this->OptOut = $a; return $this; }

  public function setPersonalDetails(PersonalDetails $a) { $this->PersonalDetails = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.registration.api.model.DefaultPersonalDetails
*/
class PersonalDetails extends NextgenObject {
  

  public $Surname;
  public $FirstName;
  public $Title;
  public $PhoneNumber;

  public function __construct() {
  }

  public function getSurname() { return $this->Surname; }

  public function getFirstName() { return $this->FirstName; }

  public function getTitle() { return $this->Title; }

  public function getPhoneNumber() { return $this->PhoneNumber; }

  public function setSurname($a) { $this->Surname = $a; return $this; }

  public function setFirstName($a) { $this->FirstName = $a; return $this; }

  public function setTitle($a) { $this->Title = $a; return $this; }

  public function setPhoneNumber($a) { $this->PhoneNumber = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.registration.api.model.DefaultCompleteRegistrationResponse
*/
class CompleteRegistrationResponse extends NextgenObject {
  

  public $RegistrationCompleted;

  public function __construct($IsRegistrationComplete = NULL) {
    $this->IsRegistrationComplete = $IsRegistrationComplete;
  }

  public function getRegistrationCompleted() { return $this->RegistrationCompleted; }

  public function setRegistrationCompleted($a) { $this->RegistrationCompleted = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.registration.api.model.DefaultCompleteRegistrationRequest
*/
class CompleteRegistrationRequest extends NextgenRequest {
  

  protected $_service = "registration";
  protected $_method = "completeRegistration";
  protected $_response = "CompleteRegistrationResponse";
  public $OneTimeToken;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct($Token = NULL) {
    $this->Token = $Token;
  }

  public function getOneTimeToken() { return $this->OneTimeToken; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setOneTimeToken(OneTimeToken $a) { $this->OneTimeToken = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.registration.api.model.DefaultRegisterDemoAccountToCustomerResponse
*/
class RegisterDemoAccountToCustomerResponse extends NextgenObject {
  

  public $Identity;
  public $PersonId;
  public $TradingAccountID;
  public $CustomerId;

  public function __construct($TradingAccountID = NULL) {
    $this->TradingAccountID = $TradingAccountID;
  }

  public function getIdentity() { return $this->Identity; }

  public function getPersonId() { return $this->PersonId; }

  public function getTradingAccountID() { return $this->TradingAccountID; }

  public function getCustomerId() { return $this->CustomerId; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }

  public function setPersonId($a) { $this->PersonId = $a; return $this; }

  public function setTradingAccountID($a) { $this->TradingAccountID = $a; return $this; }

  public function setCustomerId($a) { $this->CustomerId = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.registration.api.model.DefaultRegisterDemoAccountToCustomerRequest
*/
class RegisterDemoAccountToCustomerRequest extends NextgenRequest {
  

  protected $_service = "registration";
  protected $_method = "registerDemoAccountToCustomer";
  protected $_response = "RegisterDemoAccountToCustomerResponse";
  public $Language;
  public $Country;
  public $Currency;
  public $DeviceId;
  public $Identity;
  public $ReasonCode;
  public $IpAddress;
  public $TenantTemplateCode;
  public $OptOut;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getLanguage() { return $this->Language; }

  public function getCountry() { return $this->Country; }

  public function getCurrency() { return $this->Currency; }

  public function getDeviceId() { return $this->DeviceId; }

  public function getIdentity() { return $this->Identity; }

  public function getReasonCode() { return $this->ReasonCode; }

  public function getIpAddress() { return $this->IpAddress; }

  public function getTenantTemplateCode() { return $this->TenantTemplateCode; }

  public function getOptOut() { return $this->OptOut; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setLanguage($a) { $this->Language = $a; return $this; }

  public function setCountry($a) { $this->Country = $a; return $this; }

  public function setCurrency($a) { $this->Currency = $a; return $this; }

  public function setDeviceId($a) { $this->DeviceId = $a; return $this; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }

  public function setReasonCode($a) { $this->ReasonCode = $a; return $this; }

  public function setIpAddress($a) { $this->IpAddress = $a; return $this; }

  public function setTenantTemplateCode($a) { $this->TenantTemplateCode = $a; return $this; }

  public function setOptOut($a) { $this->OptOut = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.registration.api.model.DefaultCancelBatchJobResponse
*/
class CancelBatchJobResponse extends NextgenObject {
  

  public $Reason;
  public $SuccessfullyCancelled;
  public $SenderName;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;

  public function __construct() {
  }

  public function getReason() { return $this->Reason; }

  public function getSuccessfullyCancelled() { return $this->SuccessfullyCancelled; }

  public function getSenderName() { return $this->SenderName; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function setReason($a) { $this->Reason = $a; return $this; }

  public function setSuccessfullyCancelled($a) { $this->SuccessfullyCancelled = $a; return $this; }

  public function setSenderName($a) { $this->SenderName = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.registration.api.model.DefaultCancelBatchJobRequest
*/
class CancelBatchJobRequest extends NextgenRequest {
  

  protected $_service = "registration";
  protected $_method = "cancelBatchJob";
  protected $_response = "CancelBatchJobResponse";
  public $TaskId;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getTaskId() { return $this->TaskId; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setTaskId($a) { $this->TaskId = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.registration.api.model.DefaultFetchBatchJobsResponse
*/
class FetchBatchJobsResponse extends NextgenObject {
    protected $_collections = array (
  'Jobs' => 'BatchJob',
);

  public $Jobs;
  public $SenderName;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;

  public function __construct() {
  }

  public function getJobs() { return $this->Jobs; }

  public function getSenderName() { return $this->SenderName; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function setJobs(array $a) { $this->Jobs = $a; return $this; }

  public function setSenderName($a) { $this->SenderName = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.registration.api.model.DefaultBatchJob
*/
class BatchJob extends NextgenObject {
    protected $_collections = array (
  'Users' => 'BatchUser',
);

  public $Language;
  public $Country;
  public $Users;
  public $Status;
  public $Currency;
  public $DeviceId;
  public $TaskId;
  public $IpAddress;
  public $TenantTemplateCode;
  public $ScheduledStartTime;

  public function __construct() {
  }

  public function getLanguage() { return $this->Language; }

  public function getCountry() { return $this->Country; }

  public function getUsers() { return $this->Users; }

  public function getStatus() { return $this->Status; }

  public function getCurrency() { return $this->Currency; }

  public function getDeviceId() { return $this->DeviceId; }

  public function getTaskId() { return $this->TaskId; }

  public function getIpAddress() { return $this->IpAddress; }

  public function getTenantTemplateCode() { return $this->TenantTemplateCode; }

  public function getScheduledStartTime() { return $this->ScheduledStartTime; }

  public function setLanguage($a) { $this->Language = $a; return $this; }

  public function setCountry($a) { $this->Country = $a; return $this; }

  public function setUsers(array $a) { $this->Users = $a; return $this; }

  public function setStatus($a) { $this->Status = $a; return $this; }

  public function setCurrency($a) { $this->Currency = $a; return $this; }

  public function setDeviceId($a) { $this->DeviceId = $a; return $this; }

  public function setTaskId($a) { $this->TaskId = $a; return $this; }

  public function setIpAddress($a) { $this->IpAddress = $a; return $this; }

  public function setTenantTemplateCode($a) { $this->TenantTemplateCode = $a; return $this; }

  public function setScheduledStartTime(Date $a) { $this->ScheduledStartTime = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.registration.api.model.DefaultBatchUser
*/
class BatchUser extends NextgenObject {
  

  public $Password;
  public $Status;
  public $Reason;
  public $Identity;
  public $PersonId;
  public $EmailAddress;
  public $SuccessfullyCreated;
  public $MMSystemId;
  public $MmAccountId;

  public function __construct() {
  }

  public function getPassword() { return $this->Password; }

  public function getStatus() { return $this->Status; }

  public function getReason() { return $this->Reason; }

  public function getIdentity() { return $this->Identity; }

  public function getPersonId() { return $this->PersonId; }

  public function getEmailAddress() { return $this->EmailAddress; }

  public function getSuccessfullyCreated() { return $this->SuccessfullyCreated; }

  public function getMMSystemId() { return $this->MMSystemId; }

  public function getMmAccountId() { return $this->MmAccountId; }

  public function setPassword($a) { $this->Password = $a; return $this; }

  public function setStatus($a) { $this->Status = $a; return $this; }

  public function setReason($a) { $this->Reason = $a; return $this; }

  public function setIdentity(Identity $a) { $this->Identity = $a; return $this; }

  public function setPersonId($a) { $this->PersonId = $a; return $this; }

  public function setEmailAddress($a) { $this->EmailAddress = $a; return $this; }

  public function setSuccessfullyCreated($a) { $this->SuccessfullyCreated = $a; return $this; }

  public function setMMSystemId($a) { $this->MMSystemId = $a; return $this; }

  public function setMmAccountId($a) { $this->MmAccountId = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.registration.api.model.DefaultFetchBatchJobsRequest
*/
class FetchBatchJobsRequest extends NextgenRequest {
  

  protected $_service = "registration";
  protected $_method = "fetchBatchJobs";
  protected $_response = "FetchBatchJobsResponse";
  public $TaskId;
  public $IncludeOld;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getTaskId() { return $this->TaskId; }

  public function getIncludeOld() { return $this->IncludeOld; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setTaskId($a) { $this->TaskId = $a; return $this; }

  public function setIncludeOld($a) { $this->IncludeOld = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.registration.api.model.DefaultRunBatchJobResponse
*/
class RunBatchJobResponse extends NextgenObject {
  

  public $TaskScheduled;
  public $TaskId;
  public $SenderName;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;

  public function __construct() {
  }

  public function getTaskScheduled() { return $this->TaskScheduled; }

  public function getTaskId() { return $this->TaskId; }

  public function getSenderName() { return $this->SenderName; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function setTaskScheduled($a) { $this->TaskScheduled = $a; return $this; }

  public function setTaskId($a) { $this->TaskId = $a; return $this; }

  public function setSenderName($a) { $this->SenderName = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.registration.api.model.DefaultRunBatchJobRequest
*/
class RunBatchJobRequest extends NextgenRequest {
  

  protected $_service = "registration";
  protected $_method = "runBatchJob";
  protected $_response = "RunBatchJobResponse";
  public $UserName;
  public $Job;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getUserName() { return $this->UserName; }

  public function getJob() { return $this->Job; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setUserName($a) { $this->UserName = $a; return $this; }

  public function setJob(BatchJob $a) { $this->Job = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.content.api.model.DefaultGetContentResponse
*/
class GetContentResponse extends NextgenObject {
    protected $_collections = array (
  'ContentsList' => 'ContentData',
);

  public $ContentsList;
  public $SenderName;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;

  public function __construct() {
  }

  public function getContentsList() { return $this->ContentsList; }

  public function getSenderName() { return $this->SenderName; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function setContentsList(array $a) { $this->ContentsList = $a; return $this; }

  public function setSenderName($a) { $this->SenderName = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.content.api.model.DefaultContentData
*/
class ContentData extends NextgenObject {
  

  public $LastModifiedDate;
  public $ContentID;
  public $Headline;
  public $Introduction;
  public $Author;
  public $ContentStatus;
  public $ContentVersion;
  public $PublishDate;
  public $ContentMetaData;
  public $WebsiteUri;
  public $ContentAbstract;
  public $LastModifiedBy;
  public $PublishStatus;

  public function __construct() {
  }

  public function getLastModifiedDate() { return $this->LastModifiedDate; }

  public function getContentID() { return $this->ContentID; }

  public function getHeadline() { return $this->Headline; }

  public function getIntroduction() { return $this->Introduction; }

  public function getAuthor() { return $this->Author; }

  public function getContentStatus() { return $this->ContentStatus; }

  public function getContentVersion() { return $this->ContentVersion; }

  public function getPublishDate() { return $this->PublishDate; }

  public function getContentMetaData() { return $this->ContentMetaData; }

  public function getWebsiteUri() { return $this->WebsiteUri; }

  public function getContentAbstract() { return $this->ContentAbstract; }

  public function getLastModifiedBy() { return $this->LastModifiedBy; }

  public function getPublishStatus() { return $this->PublishStatus; }

  public function setLastModifiedDate($a) { $this->LastModifiedDate = $a; return $this; }

  public function setContentID($a) { $this->ContentID = $a; return $this; }

  public function setHeadline(HeadlineData $a) { $this->Headline = $a; return $this; }

  public function setIntroduction($a) { $this->Introduction = $a; return $this; }

  public function setAuthor($a) { $this->Author = $a; return $this; }

  public function setContentStatus($a) { $this->ContentStatus = $a; return $this; }

  public function setContentVersion($a) { $this->ContentVersion = $a; return $this; }

  public function setPublishDate($a) { $this->PublishDate = $a; return $this; }

  public function setContentMetaData(ContentMetaData $a) { $this->ContentMetaData = $a; return $this; }

  public function setWebsiteUri($a) { $this->WebsiteUri = $a; return $this; }

  public function setContentAbstract($a) { $this->ContentAbstract = $a; return $this; }

  public function setLastModifiedBy($a) { $this->LastModifiedBy = $a; return $this; }

  public function setPublishStatus($a) { $this->PublishStatus = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.content.api.model.DefaultHeadlineData
*/
class HeadlineData extends NextgenObject {
  

  public $NewsHeadline;
  public $TwitterHeadline;
  public $FacebookHeadline;
  public $MsliveHeadline;

  public function __construct() {
  }

  public function getNewsHeadline() { return $this->NewsHeadline; }

  public function getTwitterHeadline() { return $this->TwitterHeadline; }

  public function getFacebookHeadline() { return $this->FacebookHeadline; }

  public function getMsliveHeadline() { return $this->MsliveHeadline; }

  public function setNewsHeadline($a) { $this->NewsHeadline = $a; return $this; }

  public function setTwitterHeadline($a) { $this->TwitterHeadline = $a; return $this; }

  public function setFacebookHeadline($a) { $this->FacebookHeadline = $a; return $this; }

  public function setMsliveHeadline($a) { $this->MsliveHeadline = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.content.api.model.DefaultContentMetaData
*/
class ContentMetaData extends NextgenObject {
    protected $_collections = array (
  'ProductKeysList' => 'ProductKey',
  'ProductCategoriesList' => 'ProductCategory',
);

  public $Language;
  public $ContentType;
  public $ProductKeysList;
  public $SourceType;
  public $ProductCategoriesList;
  public $HighPriority;
  public $StoryCategoryList;

  public function __construct() {
  }

  public function getLanguage() { return $this->Language; }

  public function getContentType() { return $this->ContentType; }

  public function getProductKeysList() { return $this->ProductKeysList; }

  public function getSourceType() { return $this->SourceType; }

  public function getProductCategoriesList() { return $this->ProductCategoriesList; }

  public function getHighPriority() { return $this->HighPriority; }

  public function getStoryCategoryList() { return $this->StoryCategoryList; }

  public function setLanguage($a) { $this->Language = $a; return $this; }

  public function setContentType($a) { $this->ContentType = $a; return $this; }

  public function setProductKeysList(array $a) { $this->ProductKeysList = $a; return $this; }

  public function setSourceType($a) { $this->SourceType = $a; return $this; }

  public function setProductCategoriesList(array $a) { $this->ProductCategoriesList = $a; return $this; }

  public function setHighPriority($a) { $this->HighPriority = $a; return $this; }

  public function setStoryCategoryList(array $a) { $this->StoryCategoryList = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.framework.messaging.common.model.DefaultProductKey
*/
class ProductKey extends NextgenObject {
  

  public $ProductWrapperCode;
  public $InstrumentCode;

  public function __construct() {
  }

  public function getProductWrapperCode() { return $this->ProductWrapperCode; }

  public function getInstrumentCode() { return $this->InstrumentCode; }

  public function setProductWrapperCode($a) { $this->ProductWrapperCode = $a; return $this; }

  public function setInstrumentCode($a) { $this->InstrumentCode = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.content.api.model.DefaultProductCategory
*/
class ProductCategory extends NextgenObject {
  

  public $ProductCategoryCode;

  public function __construct() {
  }

  public function getProductCategoryCode() { return $this->ProductCategoryCode; }

  public function setProductCategoryCode($a) { $this->ProductCategoryCode = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.content.api.model.DefaultGetContentRequest
*/
class GetContentRequest extends NextgenRequest {
  

  protected $_service = "content";
  protected $_method = "getContent";
  protected $_response = "GetContentResponse";
  public $ContentFilter;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getContentFilter() { return $this->ContentFilter; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setContentFilter(ContentFilter $a) { $this->ContentFilter = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.content.api.model.DefaultContentFilter
*/
class ContentFilter extends NextgenObject {
    protected $_collections = array (
  'ProductKeysList' => 'ProductKey',
  'ProductCategoriesList' => 'ProductCategory',
);

  public $Language;
  public $Keyword;
  public $SourceTypes;
  public $ContentStart;
  public $ContentEnd;
  public $StoryCategory;
  public $ProductKeysList;
  public $ProductCategoriesList;
  public $HighPriority;
  public $ContentTypes;
  public $NumberOfItems;
  public $GsaSearchTypeList;
  public $StoryCategoryParent;

  public function __construct() {
  }

  public function getLanguage() { return $this->Language; }

  public function getKeyword() { return $this->Keyword; }

  public function getSourceTypes() { return $this->SourceTypes; }

  public function getContentStart() { return $this->ContentStart; }

  public function getContentEnd() { return $this->ContentEnd; }

  public function getStoryCategory() { return $this->StoryCategory; }

  public function getProductKeysList() { return $this->ProductKeysList; }

  public function getProductCategoriesList() { return $this->ProductCategoriesList; }

  public function getHighPriority() { return $this->HighPriority; }

  public function getContentTypes() { return $this->ContentTypes; }

  public function getNumberOfItems() { return $this->NumberOfItems; }

  public function getGsaSearchTypeList() { return $this->GsaSearchTypeList; }

  public function getStoryCategoryParent() { return $this->StoryCategoryParent; }

  public function setLanguage($a) { $this->Language = $a; return $this; }

  public function setKeyword($a) { $this->Keyword = $a; return $this; }

  public function setSourceTypes($a) { $this->SourceTypes = $a; return $this; }

  public function setContentStart($a) { $this->ContentStart = $a; return $this; }

  public function setContentEnd($a) { $this->ContentEnd = $a; return $this; }

  public function setStoryCategory($a) { $this->StoryCategory = $a; return $this; }

  public function setProductKeysList(array $a) { $this->ProductKeysList = $a; return $this; }

  public function setProductCategoriesList(array $a) { $this->ProductCategoriesList = $a; return $this; }

  public function setHighPriority($a) { $this->HighPriority = $a; return $this; }

  public function setContentTypes($a) { $this->ContentTypes = $a; return $this; }

  public function setNumberOfItems($a) { $this->NumberOfItems = $a; return $this; }

  public function setGsaSearchTypeList(array $a) { $this->GsaSearchTypeList = $a; return $this; }

  public function setStoryCategoryParent($a) { $this->StoryCategoryParent = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.content.api.model.DefaultGetContentItemResponse
*/
class GetContentItemResponse extends NextgenObject {
    protected $_collections = array (
  'ContentBodiesList' => 'ContentDataBody',
);

  public $ContentBodiesList;
  public $SenderName;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;

  public function __construct() {
  }

  public function getContentBodiesList() { return $this->ContentBodiesList; }

  public function getSenderName() { return $this->SenderName; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function setContentBodiesList(array $a) { $this->ContentBodiesList = $a; return $this; }

  public function setSenderName($a) { $this->SenderName = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.content.api.model.DefaultContentDataBody
*/
class ContentDataBody extends NextgenObject {
    protected $_collections = array (
  'ContentsList' => 'ContentData',
);

  public $ContentID;
  public $ContentsList;
  public $ContentBody;

  public function __construct() {
  }

  public function getContentID() { return $this->ContentID; }

  public function getContentsList() { return $this->ContentsList; }

  public function getContentBody() { return $this->ContentBody; }

  public function setContentID($a) { $this->ContentID = $a; return $this; }

  public function setContentsList(array $a) { $this->ContentsList = $a; return $this; }

  public function setContentBody($a) { $this->ContentBody = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.content.api.model.DefaultGetContentItemRequest
*/
class GetContentItemRequest extends NextgenRequest {
  

  protected $_service = "content";
  protected $_method = "getContentItem";
  protected $_response = "GetContentItemResponse";
  public $ContentIDsList;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getContentIDsList() { return $this->ContentIDsList; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setContentIDsList(array $a) { $this->ContentIDsList = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.content.api.model.DefaultGetContentSearchRequest
*/
class GetContentSearchRequest extends NextgenRequest {
  

  protected $_service = "content";
  protected $_method = "getContentSearch";
  protected $_response = "GetContentResponse";
  public $Language;
  public $Keyword;
  public $SearchContentType;
  public $SearchSourceType;
  public $RecordsNo;
  public $AdvancedFilter;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getLanguage() { return $this->Language; }

  public function getKeyword() { return $this->Keyword; }

  public function getSearchContentType() { return $this->SearchContentType; }

  public function getSearchSourceType() { return $this->SearchSourceType; }

  public function getRecordsNo() { return $this->RecordsNo; }

  public function getAdvancedFilter() { return $this->AdvancedFilter; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setLanguage($a) { $this->Language = $a; return $this; }

  public function setKeyword($a) { $this->Keyword = $a; return $this; }

  public function setSearchContentType($a) { $this->SearchContentType = $a; return $this; }

  public function setSearchSourceType($a) { $this->SearchSourceType = $a; return $this; }

  public function setRecordsNo($a) { $this->RecordsNo = $a; return $this; }

  public function setAdvancedFilter(AdvancedFilter $a) { $this->AdvancedFilter = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.content.api.model.DefaultAdvancedFilter
*/
class AdvancedFilter extends NextgenObject {
  

  public $Phrases;
  public $Preference;
  public $Links;
  public $StartDate;
  public $EndDate;
  public $SearchTypesList;

  public function __construct() {
  }

  public function getPhrases() { return $this->Phrases; }

  public function getPreference() { return $this->Preference; }

  public function getLinks() { return $this->Links; }

  public function getStartDate() { return $this->StartDate; }

  public function getEndDate() { return $this->EndDate; }

  public function getSearchTypesList() { return $this->SearchTypesList; }

  public function setPhrases(Phrase $a) { $this->Phrases = $a; return $this; }

  public function setPreference(Preferences $a) { $this->Preference = $a; return $this; }

  public function setLinks($a) { $this->Links = $a; return $this; }

  public function setStartDate($a) { $this->StartDate = $a; return $this; }

  public function setEndDate($a) { $this->EndDate = $a; return $this; }

  public function setSearchTypesList(array $a) { $this->SearchTypesList = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.content.api.model.DefaultPhrase
*/
class Phrase extends NextgenObject {
  

  public $AllWords;
  public $ExactPhrase;
  public $AtLeastOneWord;
  public $WithoutWord;

  public function __construct() {
  }

  public function getAllWords() { return $this->AllWords; }

  public function getExactPhrase() { return $this->ExactPhrase; }

  public function getAtLeastOneWord() { return $this->AtLeastOneWord; }

  public function getWithoutWord() { return $this->WithoutWord; }

  public function setAllWords($a) { $this->AllWords = $a; return $this; }

  public function setExactPhrase($a) { $this->ExactPhrase = $a; return $this; }

  public function setAtLeastOneWord($a) { $this->AtLeastOneWord = $a; return $this; }

  public function setWithoutWord($a) { $this->WithoutWord = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.content.api.model.DefaultPreferences
*/
class Preferences extends NextgenObject {
  

  public $Sort;
  public $FileFilter;
  public $OccurrenceType;
  public $DomainFilter;

  public function __construct() {
  }

  public function getSort() { return $this->Sort; }

  public function getFileFilter() { return $this->FileFilter; }

  public function getOccurrenceType() { return $this->OccurrenceType; }

  public function getDomainFilter() { return $this->DomainFilter; }

  public function setSort($a) { $this->Sort = $a; return $this; }

  public function setFileFilter(FileFormat $a) { $this->FileFilter = $a; return $this; }

  public function setOccurrenceType($a) { $this->OccurrenceType = $a; return $this; }

  public function setDomainFilter(Domain $a) { $this->DomainFilter = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.content.api.model.DefaultFileFormat
*/
class FileFormat extends NextgenObject {
  

  public $FilterType;
  public $FileType;

  public function __construct() {
  }

  public function getFilterType() { return $this->FilterType; }

  public function getFileType() { return $this->FileType; }

  public function setFilterType($a) { $this->FilterType = $a; return $this; }

  public function setFileType($a) { $this->FileType = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.content.api.model.DefaultDomain
*/
class Domain extends NextgenObject {
  

  public $FilterType;
  public $DomainValue;

  public function __construct() {
  }

  public function getFilterType() { return $this->FilterType; }

  public function getDomainValue() { return $this->DomainValue; }

  public function setFilterType($a) { $this->FilterType = $a; return $this; }

  public function setDomainValue($a) { $this->DomainValue = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.content.api.model.DefaultGetContentPopularResponse
*/
class GetContentPopularResponse extends NextgenObject {
    protected $_collections = array (
  'PopularStoriesList' => 'PopularStory',
  'PopularKeywordsList' => 'PopularKeyword',
  'PopularProductsList' => 'PopularProduct',
);

  public $PopularStoriesList;
  public $PopularKeywordsList;
  public $PopularProductsList;
  public $SenderName;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;

  public function __construct() {
  }

  public function getPopularStoriesList() { return $this->PopularStoriesList; }

  public function getPopularKeywordsList() { return $this->PopularKeywordsList; }

  public function getPopularProductsList() { return $this->PopularProductsList; }

  public function getSenderName() { return $this->SenderName; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function setPopularStoriesList(array $a) { $this->PopularStoriesList = $a; return $this; }

  public function setPopularKeywordsList(array $a) { $this->PopularKeywordsList = $a; return $this; }

  public function setPopularProductsList(array $a) { $this->PopularProductsList = $a; return $this; }

  public function setSenderName($a) { $this->SenderName = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.content.api.model.DefaultPopularStory
*/
class PopularStory extends NextgenObject {
  

  public $ContentID;
  public $Headline;

  public function __construct() {
  }

  public function getContentID() { return $this->ContentID; }

  public function getHeadline() { return $this->Headline; }

  public function setContentID($a) { $this->ContentID = $a; return $this; }

  public function setHeadline($a) { $this->Headline = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.content.api.model.DefaultPopularKeyword
*/
class PopularKeyword extends NextgenObject {
  

  public $Keyword;

  public function __construct() {
  }

  public function getKeyword() { return $this->Keyword; }

  public function setKeyword($a) { $this->Keyword = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.content.api.model.DefaultPopularProduct
*/
class PopularProduct extends NextgenObject {
  

  public $Product;

  public function __construct() {
  }

  public function getProduct() { return $this->Product; }

  public function setProduct($a) { $this->Product = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.content.api.model.DefaultGetContentPopularRequest
*/
class GetContentPopularRequest extends NextgenRequest {
  

  protected $_service = "content";
  protected $_method = "getContentPopular";
  protected $_response = "GetContentPopularResponse";
  public $Language;
  public $ContentType;
  public $SourceTypes;
  public $TopRecords;
  public $ContentStart;
  public $ContentEnd;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getLanguage() { return $this->Language; }

  public function getContentType() { return $this->ContentType; }

  public function getSourceTypes() { return $this->SourceTypes; }

  public function getTopRecords() { return $this->TopRecords; }

  public function getContentStart() { return $this->ContentStart; }

  public function getContentEnd() { return $this->ContentEnd; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setLanguage($a) { $this->Language = $a; return $this; }

  public function setContentType($a) { $this->ContentType = $a; return $this; }

  public function setSourceTypes($a) { $this->SourceTypes = $a; return $this; }

  public function setTopRecords($a) { $this->TopRecords = $a; return $this; }

  public function setContentStart($a) { $this->ContentStart = $a; return $this; }

  public function setContentEnd($a) { $this->ContentEnd = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.content.api.model.DefaultPublishContentResponse
*/
class PublishContentResponse extends NextgenObject {
  

  public $ContentID;
  public $Success;
  public $SenderName;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;

  public function __construct() {
  }

  public function getContentID() { return $this->ContentID; }

  public function getSuccess() { return $this->Success; }

  public function getSenderName() { return $this->SenderName; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function setContentID($a) { $this->ContentID = $a; return $this; }

  public function setSuccess($a) { $this->Success = $a; return $this; }

  public function setSenderName($a) { $this->SenderName = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }
}

/*
    Equivalent to com.cmcmarkets.content.api.model.DefaultPublishContentRequest
*/
class PublishContentRequest extends NextgenRequest {
    protected $_collections = array (
  'ProductKeysList' => 'ProductKey',
);

  protected $_service = "content";
  protected $_method = "publishContent";
  protected $_response = "PublishContentResponse";
  public $Language;
  public $ContentID;
  public $Abstract;
  public $Destination;
  public $ContentTypesList;
  public $SourceTypesList;
  public $Headline;
  public $ContentBody;
  public $StoryCategory;
  public $Introduction;
  public $Author;
  public $ProductKeysList;
  public $ContentStatus;
  public $ContentVersion;
  public $InstrumentsList;
  public $RequestMode;
  public $ScheduledPublishing;
  public $ScheduledPublishingDate;
  public $Channel;
  public $TimeToLive;
  public $Function;
  public $RequestID;
  public $SenderSecurityToken;
  public $ExpirationTime;
  public $CorrelationID;
  public $IdempotentID;
  public $SessionKey;
  public $OnBehalfOfIdentity;
  public $SenderIdentity;

  public function __construct() {
  }

  public function getLanguage() { return $this->Language; }

  public function getContentID() { return $this->ContentID; }

  public function getAbstract() { return $this->Abstract; }

  public function getDestination() { return $this->Destination; }

  public function getContentTypesList() { return $this->ContentTypesList; }

  public function getSourceTypesList() { return $this->SourceTypesList; }

  public function getHeadline() { return $this->Headline; }

  public function getContentBody() { return $this->ContentBody; }

  public function getStoryCategory() { return $this->StoryCategory; }

  public function getIntroduction() { return $this->Introduction; }

  public function getAuthor() { return $this->Author; }

  public function getProductKeysList() { return $this->ProductKeysList; }

  public function getContentStatus() { return $this->ContentStatus; }

  public function getContentVersion() { return $this->ContentVersion; }

  public function getInstrumentsList() { return $this->InstrumentsList; }

  public function getRequestMode() { return $this->RequestMode; }

  public function getScheduledPublishing() { return $this->ScheduledPublishing; }

  public function getScheduledPublishingDate() { return $this->ScheduledPublishingDate; }

  public function getChannel() { return $this->Channel; }

  public function getTimeToLive() { return $this->TimeToLive; }

  public function getFunction() { return $this->Function; }

  public function getRequestID() { return $this->RequestID; }

  public function getSenderSecurityToken() { return $this->SenderSecurityToken; }

  public function getExpirationTime() { return $this->ExpirationTime; }

  public function getCorrelationID() { return $this->CorrelationID; }

  public function getIdempotentID() { return $this->IdempotentID; }

  public function getSessionKey() { return $this->SessionKey; }

  public function getOnBehalfOfIdentity() { return $this->OnBehalfOfIdentity; }

  public function getSenderIdentity() { return $this->SenderIdentity; }

  public function setLanguage($a) { $this->Language = $a; return $this; }

  public function setContentID($a) { $this->ContentID = $a; return $this; }

  public function setAbstract($a) { $this->Abstract = $a; return $this; }

  public function setDestination($a) { $this->Destination = $a; return $this; }

  public function setContentTypesList(array $a) { $this->ContentTypesList = $a; return $this; }

  public function setSourceTypesList(array $a) { $this->SourceTypesList = $a; return $this; }

  public function setHeadline(HeadlineData $a) { $this->Headline = $a; return $this; }

  public function setContentBody($a) { $this->ContentBody = $a; return $this; }

  public function setStoryCategory($a) { $this->StoryCategory = $a; return $this; }

  public function setIntroduction($a) { $this->Introduction = $a; return $this; }

  public function setAuthor($a) { $this->Author = $a; return $this; }

  public function setProductKeysList(array $a) { $this->ProductKeysList = $a; return $this; }

  public function setContentStatus($a) { $this->ContentStatus = $a; return $this; }

  public function setContentVersion($a) { $this->ContentVersion = $a; return $this; }

  public function setInstrumentsList(array $a) { $this->InstrumentsList = $a; return $this; }

  public function setRequestMode($a) { $this->RequestMode = $a; return $this; }

  public function setScheduledPublishing($a) { $this->ScheduledPublishing = $a; return $this; }

  public function setScheduledPublishingDate($a) { $this->ScheduledPublishingDate = $a; return $this; }

  public function setChannel($a) { $this->Channel = $a; return $this; }

  public function setTimeToLive($a) { $this->TimeToLive = $a; return $this; }

  public function setFunction($a) { $this->Function = $a; return $this; }

  public function setRequestID($a) { $this->RequestID = $a; return $this; }

  public function setSenderSecurityToken($a) { $this->SenderSecurityToken = $a; return $this; }

  public function setExpirationTime($a) { $this->ExpirationTime = $a; return $this; }

  public function setCorrelationID($a) { $this->CorrelationID = $a; return $this; }

  public function setIdempotentID($a) { $this->IdempotentID = $a; return $this; }

  public function setSessionKey($a) { $this->SessionKey = $a; return $this; }

  public function setOnBehalfOfIdentity(Identity $a) { $this->OnBehalfOfIdentity = $a; return $this; }

  public function setSenderIdentity(Identity $a) { $this->SenderIdentity = $a; return $this; }
}