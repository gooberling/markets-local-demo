<?xml version="1.0" encoding="utf-8"?>
<xs:schema id="ApplicationForm" xmlns:xs="http://www.w3.org/2001/XMLSchema">
	<xs:element name="ApplicationForm">
		<xs:complexType>
			<xs:sequence>
				<xs:element name="RequestType">
					<xs:simpleType>
						<xs:restriction base="xs:string">
							<xs:enumeration value="Score"/>
							<xs:enumeration value="Submit"/>
						</xs:restriction>
					</xs:simpleType>
				</xs:element>
				<xs:element name="TenantTemplateCode" type="xs:string" minOccurs="1" maxOccurs="1"/>
				<xs:element name="TradingCurrency" type="xs:string" minOccurs="1" maxOccurs="1"/>
				<xs:element name="ApplicationDate" type="xs:string" />
				<xs:element name="ApplicationType" type="xs:string" minOccurs="1" maxOccurs="1"/>
				<xs:element name="Language" type="xs:string" />
				<xs:element name="SalesTraderFlag" type="xs:boolean" />
				<xs:element name="IPAddress" type="xs:string" />
				<xs:element name="DeviceId" type="xs:string" />
				<xs:element name="AcceptanceofAssessment" type="xs:boolean" />
				<xs:element name="ApplicationChannel" type="CodeValuePair" minOccurs="1" maxOccurs="1" />
				<xs:element name="PersonalDetails" minOccurs="1" maxOccurs="1">
					<xs:complexType>
					  <xs:sequence>
						<xs:element name="Title" type="xs:string" />
						<xs:element name="FirstName" type="xs:string" />
						<xs:element name="LastName" type="xs:string" />
						<xs:element name="Gender" type="xs:string" />
						<xs:element name="DateOfBirth" type="xs:string" />
						<xs:element name="Nationality" type="xs:string" />
						<xs:element name="MobileNumber" type="xs:string" />
						<xs:element name="HomeNumber" type="xs:string" />
						<xs:element name="EmailAddress" type="xs:string" />
					  </xs:sequence>
					</xs:complexType>
				</xs:element>
				<xs:element name="Address" minOccurs="1" maxOccurs="1">
					<xs:complexType>
					  <xs:sequence>
						<xs:element name="ServiceAddressID" type="xs:string" />
						<xs:element name="AddressLine1" type="xs:string" />
						<xs:element name="AddressLine2" type="xs:string" />
						<xs:element name="AddressLine3" type="xs:string" />
						<xs:element name="AddressLine4" type="xs:string" />
						<xs:element name="AddressLine5" type="xs:string" />
						<xs:element name="Country" type="xs:string" />
						<xs:element name="PostalCode" type="xs:string" />
					  </xs:sequence>
					</xs:complexType>
				</xs:element>
				<xs:element name="BankDetails">
					<xs:complexType>
					  <xs:sequence>
						<xs:element name="SortCode" type="xs:string" />
						<xs:element name="AccountNumber" type="xs:string" />
						<xs:element name="IBAN" type="xs:string" />
						<xs:element name="SWIFTCode" type="xs:string" />
						<xs:element name="BankAccountCountry" type="xs:string" />
						<xs:element name="IsValid" type="xs:boolean" />
						<xs:element name="IsVerified" type="xs:boolean" />
					  </xs:sequence>
					</xs:complexType>
				</xs:element>
				<xs:element name="IdentificationDetails">
					<xs:complexType>
					  <xs:sequence>
						<xs:element name="IDType" type="xs:string" />
						<xs:element name="Identification" type="xs:string" />
						<xs:element name="AdditionalDetails" type="xs:string" />
						<xs:element name="ExpiryDate" type="xs:string" />
					  </xs:sequence>
					</xs:complexType>
				</xs:element>
				<xs:element name="FinancialDetails">
					<xs:complexType>
					  <xs:sequence>
						<xs:element name="EmploymentStatus" type="CodeValuePair" />
						<xs:element name="JobTitle" type="CodeValuePair"/>
						<xs:element name="CompanyName" type="xs:string" />
						<xs:element name="CompanyRegistrationNumber" minOccurs="0" type="xs:string" />  <!-- ABN -->
						<xs:element name="EducationalEstablishmentName" type="xs:string" />
						<xs:element name="NatureOfBusiness" type="CodeValuePair" />
						<xs:element name="NatureOfBusinessFurtherDetails" type="CodeValuePair" />
						<xs:element name="SourceOfFunds" type="CodeValuePair" />
						<xs:element name="AnnualIncome" type="CodeValuePair" />
						<xs:element name="ValueOfSavings" type="CodeValuePair" />
						<xs:element name="SourceOfIncome" type="CodeValuePair" />
						<xs:element name="OtherSourceOfIncome" type="CodeValuePair" />
						<xs:element name="EmpAddress" minOccurs="0" maxOccurs="1">
							<xs:complexType>
								<xs:sequence>
									<xs:element name="AddressLine1" type="xs:string" />
									<xs:element name="AddressLine2" type="xs:string" />
									<xs:element name="AddressLine3" type="xs:string" />
									<xs:element name="AddressLine4" type="xs:string" />
									<xs:element name="AddressLine5" type="xs:string" />
									<xs:element name="Country" type="xs:string" />
									<xs:element name="PostalCode" type="xs:string" />
								</xs:sequence>
							</xs:complexType>
						</xs:element>
					  </xs:sequence>
					</xs:complexType>
				</xs:element>
				<xs:element name="TradingRelevantExperience">
					<xs:complexType>
						<xs:sequence>
							<xs:element name="TradedAnyShares" type="CodeValuePair" />
							<xs:element name="TradedAnyOTCDerivatives" type="CodeValuePair" />
							<xs:element name="TradedAnyETD" type="CodeValuePair" />
							<xs:element name="IsDemoAccountExist" type="xs:boolean" />
							<xs:element name="IsSeminarAttended" type="xs:boolean" />
							<xs:element name="WorkExperience" minOccurs="0" type="CodeValuePair" />
							<xs:element name="ProfessionalQualification" minOccurs="0" type="CodeValuePair" />
							<xs:element name="InvestmentExperience" type="CodeValuePair" />
							<xs:element name="NoOfYearsExperience" type="CodeValuePair" />
							<xs:element name="NoOfTransactions" type="CodeValuePair" />
						</xs:sequence>
					</xs:complexType>
				</xs:element>
				<xs:element name="UnderstandingOfTheFeaturesAndRisks">
					<xs:complexType>
					  <xs:sequence>
						<xs:element name="OwnershipAndRights" type="xs:boolean" />
						<xs:element name="ConceptOfMarginAndLeverage" type="xs:boolean" />
						<xs:element name="ConceptOfVolatility" type="xs:boolean" />
						<xs:element name="FamiliarWithOnlinePlatform" type="xs:boolean" />
						<xs:element name="ResponsibilityToMonitorAndManage" type="xs:boolean" />
					  </xs:sequence>
					</xs:complexType>
				</xs:element>
				<xs:element name="LegalAgreement" minOccurs="0" maxOccurs="1">
					<xs:complexType>
					  <xs:sequence>
						<xs:element name="CreditConsentGiven" minOccurs="0" type="xs:boolean" />					  
						<xs:element name="ReceiveMarketingData" minOccurs="0" type="xs:string" />
						<xs:element name="TermsAndConditions" minOccurs="0" type="xs:string" />
						<xs:element name="TermsOfBusinessDocName" minOccurs="1" type="xs:string" />
						<xs:element name="TermsOfBusinessVersion" minOccurs="1" type="xs:string" />
						<xs:element name="TermsOfBusinessDateApproved" minOccurs="1" type="xs:string" />
					  </xs:sequence>
					</xs:complexType>
				</xs:element>
				<xs:element name="Identity" minOccurs="0">
					<xs:complexType>
					  <xs:sequence>
						<xs:element name="ID" type="xs:string" />
					  </xs:sequence>
					</xs:complexType>
				</xs:element>
            </xs:sequence>
		</xs:complexType>
	</xs:element>
	

	<xs:element name="ApplicationFormResponse">
		<xs:complexType>
			<xs:sequence>
				<xs:element name="ApplicationID" type="xs:string" />
				<xs:element name="Status" type="xs:string" />
      </xs:sequence>
		</xs:complexType>
	</xs:element>


	<xs:complexType name="CodeValuePair">
		<xs:sequence>
			<xs:element name="Code" type="xs:string" />
			<xs:element name="Value" type="xs:string" />
		</xs:sequence>
	</xs:complexType>

	
</xs:schema>
