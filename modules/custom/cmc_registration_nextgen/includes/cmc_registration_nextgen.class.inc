<?php 
/**
 * Creates required Application Class objects that can be passed to PEGA via SOAP service 
 */

/**
 * Personal Details Class 
 */

class PersonalDetails {
  protected $Title;
	protected $FirstName;
	protected $LastName;
	protected $Gender;
	protected $DateOfBirth;
	protected $Nationality;
	protected $MobileNumber;
	protected $HomeNumber;
	protected $EmailAddress;
  
  public function __set($name, $value) {
    $this->$name = $value;
  }
  public function __get($name) {
    return $name;
  }
}

/**
 * Address Details 
 */
class Address {
  protected $ServiceAddressID;
	protected $AddressLine1;
	protected $AddressLine2;
	protected $AddressLine3;
	protected $AddressLine4;
	protected $AddressLine5;
	protected $Country;
	protected $PostalCode;
  
  public function __set($name, $value) {
    $this->$name = $value;
  }
  
  public function __get($name) {
    return $name;
  } 
}

/**
 * Bank Details Class 
 */
class BankDetails {
  protected $SortCode;
	protected $AccountNumber;
	protected $IBAN;
	protected $SWIFTCode;
	protected $BankAccountCountry;
	protected $IsValid;
	protected $IsVerified;
  
  public function __set($name, $value) {
    $this->$name = $value;
  }
  
  public function __get($name) {
    return $name;
  } 
}

/**
 * Identification Details 
 */
class IdentificationDetails {
  protected $IDType;
	protected $Identification;
	protected $AdditionalDetails;
	protected $ExpiryDate;
  
  public function __set($name, $value) {
    $this->$name = $value;
  }
  
  public function __get($name) {
    return $name;
  }
}


/**
 * Financial Details Class 
 */
class FinancialDetails {
  protected $EmploymentStatus;
	protected $JobTitle;
	protected $CompanyName;
	protected $CompanyRegistrationNumber;
	protected $EducationalEstablishmentName;
	protected $NatureOfBusiness;
	protected $NatureOfBusinessFurtherDetails;
	protected $SourceOfFunds;
	protected $AnnualIncome;
	protected $ValueOfSavings;
	protected $SourceOfIncome;
	protected $OtherSourceOfIncome;
	protected $EmpAddress;
  
  function __construct() {
    $this->EmpAddress = new Address();
  }
  
  public function __set($name, $value) {
    $this->$name = $value;
  }
  
  public function __get($name) {
    return $name;
  }
  
}

/**
 * Trading Experience 
 */
class TradingRelevantExperience {
  protected $TradedAnyShares;
	protected $TradedAnyOTCDerivatives;
	protected $TradedAnyETD;
	protected $IsDemoAccountExist;
	protected $IsSeminarAttended;
	protected $WorkExperience;
	protected $ProfessionalQualification;
	protected $InvestmentExperience;
	protected $NoOfYearsExperience;
	protected $NoOfTransactions;
    
  public function __set($name, $value) {
    $this->$name = $value;
  }
  
  public function __get($name) {
    return $this->$name;
  }
    
}

class UnderstandingOfTheFeaturesAndRisks {
  protected $OwnershipAndRights;
	protected $ConceptOfMarginAndLeverage;
	protected $ConceptOfVolatility;
	protected $FamiliarWithOnlinePlatform;
	protected $ResponsibilityToMonitorAndManage;
  
  public function __set($name, $value) {
    $this->$name = $value;
  }
  
  public function __get($name) {
    return $this->$name;
  }
}

/**
 * LEGAL AGREEMENT 
 */
class LegalAgreement {
  protected $CreditConsentGiven;				  
	protected $ReceiveMarketingData;
	protected $TermsAndConditions;
	protected $TermsOfBusinessDocName;
	protected $TermsOfBusinessVersion;
	protected $TermsOfBusinessDateApproved;
  
  public function __set($name, $value) {
    $this->$name = $value;
  }
  
  public function __get($name) {
    return $this->$name;
  }
}

class Identity {
  protected $ID;
  
  public function __set($name, $value) {
    $this->name = $value;
  }
  
  public function __get($name) {
    return $this->name;
  }
}

/**
 * Application Form Response 
 */
class ApplicationFormResponse {
  protected $ApplicationID;
  protected $Status;
  
  public function __set($name, $value) {
    $this->$name = $value;
  }
  
  public function __get($name) {
    return $this->$name;
  }
}

class CodeValuePair {
  protected $Code;
  protected $Value;
  
  function __construct($code, $value) {
    $this->Code = $code;
    $this->Value = $value;
  }
}

/**
 * crmClient provides methods and attributes for submitting applicatiosn to pega 
 */
class ApplicationForm {
  protected $RequestType;
  protected $TenantTemplateCode;
	protected $TradingCurrency;
	protected $ApplicationDate;
	protected $ApplicationType;
	protected $Language;
  protected $SalesTraderFlag;
	protected $IPAddress;
	protected $DeviceId;
	protected $AcceptanceofAssessment;
	protected $ApplicationChannel;
  
  
  // Complex types, these are mainly instances of other classes 
  protected $PersonalDetails;
  protected $Address;
  protected $BankDetails;
  protected $IdentificationDetails;
  protected $FinancialDetails;
  protected $TradingRelevantExperience;
  protected $UnderstandingOfTheFeaturesAndRisks;
  protected $LegalAgreement;
  protected $Identity;
  
  public function __construct() {
  }
  
  public function __set($name, $value) {
    $this->$name = $value;
  }
  
  public function __get($name) {
    return $name;
  }
  
  function populatePersonalDetails($values) {
    $email = ($values['already_registered'] == CMC_ALREADY_REGISTERED_YES) ? $values['email'] : $values['new_email'];
    $this->PersonalDetails = new PersonalDetails();
    
    $this->PersonalDetails->Title = $values['name_title'];
    $this->PersonalDetails->FirstName = $values['forename'];
    $this->PersonalDetails->LastName = $values['surname'];
    $this->PersonalDetails->Gender = $values['gender'];
    $this->PersonalDetails->DateOfBirth = "23/05/1990";
    $this->PersonalDetails->Nationality = $values['nationality'];
    $this->PersonalDetails->MobileNumber = $values['other_phone'];
    $this->PersonalDetails->HomeNumber = $values['phone'];
    $this->PersonalDetails->EmailAddress = $email;
  }
  
  function populateAddress($values) {
    $this->Address = new Address();

    $this->Address->AddressLine1 = $values['address_1'];
    $this->Address->AddressLine2 = $values['address_2'];
    $this->Address->AddressLine3 = $values['address_3'];
    $this->Address->AddressLine4 = $values['address_4'];
    $this->Address->AddressLine5 = $values['address_5'];
    $this->Address->Country = $values['nationality'];
    $this->Address->PostalCode = $values['other_phone'];
    
  }
  
  function populateBankDetails($values) {
    $this->BankDetails = new BankDetails();
    
    $this->BankDetails->SortCode = $values['sortcode'];
    $this->BankDetails->AccountNumber = $values['account'];
//    $this->BankDetails->IBAN = $values['iban'];
//    $this->BankDetails->$values['iban'];
    $this->BankDetails->BankAccountCountry = "GBR";
    $this->BankDetails->IsValid = FALSE;
    $this->BankDetails->IsVerified = FALSE;
  }
  
  /**
   * @todo Additional Details / Expiry Details
   * @param type $values 
   */
  function populateIdentificationDetails($values) {
    $this->IdentificationDetails = new IdentificationDetails();
    
    $this->IdentificationDetails->IDType = "Driver's License Number";
    $this->IdentificationDetails->Identification = 23232323232;
   // $this->IdentificationDetails->AdditionalDetails = $values['additional_details'];
   // $this->IdentificationDetails->ExpiryDate = $values['expiry_date'];
  }
  
  /**
   * Financial Details 
   * @Todo EmpAddress
   * @Todo Compare fields against new GA and IRI SPEC
   * @param type $values 
   */
  function populateFinancialDetails($values) {
    $this->FinancialDetails = new FinancialDetails();
    
    $this->FinancialDetails->EmploymentStatus = $values['employment_status'];
    $this->FinancialDetails->JobTitle = $value['employed']['job_title'];
    
    $this->FinancialDetails->CompanyName = $value['employed']['company_name'];
    $this->FinancialDetails->CompanyRegistrationNumber = '11111';
    $this->FinancialDetails->EducationalEstablishmentName = 'Test University';
    
    $this->FinancialDetails->NatureOfBusiness = $value['employed']['business_nature'];
    $this->FinancialDetails->NatureOfBusinessFurtherDetails =  "";
    $this->FinancialDetails->SourceOfFunds = $values['origin_of_wealth'];
    
    $this->FinancialDetails->AnnualIncome = $values['annual_income'];
    $this->FinancialDetails->ValueOfSavings = $values['net_worth'];
    $this->FinancialDetails->SourceOfIncome = $values['origin_of_wealth'];
    $this->FinancialDetails->OtherSourceOfIncome = $values['Investments and Dividents'] ;
    $this->EmpAddress =  new Address();
    
  }
  
  function populateTradingRelevantExperience($values) {
    $this->TradingRelevantExperience = new TradingRelevantExperience();
    
    $this->TradingRelevantExperience->TradedAnyShares = $values['trading_experience'];
    $this->TradingRelevantExperience->TradedAnyOTCDerivatives = $values['derivatives_frequency'];
    
    $this->TradingRelevantExperience->TradedAnyETD = $values['exchange_frequency'];
    $this->TradingRelevantExperience->IsDemoAccountExist = FALSE;
    $this->TradingRelevantExperience->IsSeminarAttended = FALSE;

    $this->TradingRelevantExperience->WorkExperience = $values['work_experience'];
    $this->TradingRelevantExperience->ProfessionalQualification = $values['educational'];
    
    $this->TradingRelevantExperience->InvestmentExperience = 'CON';
    $this->TradingRelevantExperience->NoOfYearsExperience = "TOM";
    $this->TradingRelevantExperience->NoOfTransactions = "OTF";
  }

  function populateUnderstandingOfTheFeaturesAndRisks($values) {
    $this->UnderstandingOfTheFeaturesAndRisks =  new UnderstandingOfTheFeaturesAndRisks();
    
    $this->UnderstandingOfTheFeaturesAndRisks->OwnershipAndRights = TRUE;
    $this->UnderstandingOfTheFeaturesAndRisks->ConceptOfMarginAndLeverage = TRUE;
    
    $this->UnderstandingOfTheFeaturesAndRisks->ConceptOfVolatility = TRUE;
    $this->UnderstandingOfTheFeaturesAndRisks->FamiliarWithOnlinePlatform = TRUE;
    $this->UnderstandingOfTheFeaturesAndRisks->ResponsibilityToMonitorAndManage = TRUE;
 }
 
  function populateLegalAgreement($values) {
    $this->LegalAgreement = new LegalAgreement();
    $this->LegalAgreement->CreditConsentGiven = TRUE;
    $this->LegalAgreement->ReceiveMarketingData = TRUE;				  
    $this->LegalAgreement->TermsAndConditions = TRUE;
    $this->LegalAgreement->TermsOfBusinessDocName = "logintermsandconditionscmsbuk";
    $this->LegalAgreement->TermsOfBusinessVersion ="3";				  
    $this->LegalAgreement->TermsOfBusinessDateApproved ="2012-07-10T11:26:17";		
  }

  function populateIdentity($values) {
    $this->Identity = new Identity();
    $this->Identity->ID = "1713064025";
  }
 
  public function build_request($request_type, $values) {
    // Build General Configurations
  
   
    $this->TenantTemplateCode = $values['tenant_template_code'];
    $this->TradingCurrency = "GBP";
    
    $this->ApplicationDate = date('dd/mm/yyyy', REQUEST_TIME);
    $this->ApplicationType = "JA";
    $this->IPAddress = "10.221.131.244";
    $this->AcceptanceofAssessment = 'true';
    $this->ApplicationChannel = new CodeValuePair(3, 'Online');
    $this->RequestType = $request_type;
    
    print_r($values);
    
    
    // Build all required objects
    $this->populatePersonalDetails($values);
    $this->populateAddress($values);
    $this->populateBankDetails($values);

    $this->populateIdentificationDetails($values);
    $this->populateFinancialDetails($values);
    $this->populateTradingRelevantExperience($values);
    $this->populateUnderstandingOfTheFeaturesAndRisks($values);
 
    $this->populateLegalAgreement($values);
    $this->populateIdentity($values);

  }
  

  public function prepareXML() {
    $xml;
    
    $root = get_class($this);
    $xml = new SimpleXMLElement("<{$root}></{$root}>");
    foreach($this as $key => $item) {
      if (is_object($item) || is_array($item)) {
        $child = $xml->addChild($key); 
        $this->prepareChildElements($item, $child);
      } 
      else {
        $xml->addChild($key, $item); 
      }
    }
    
    return $xml->asXML();
  }
  
  private function prepareChildElements($item, &$xml) {
    $child;
    foreach($item as $childKey => $childItem) {
      if (is_object($childItem) || is_array($childItem)) {
        $child = $xml->addChild($key); 
        //$this->prepareChildElements($item, $child);
      } 
      else {
        $xml->addChild($childKey, $childItem); 
      }
    }
  }
}