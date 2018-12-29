#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void dashboard();
void addPatient();
void searched();
void emergency();
void BedBooked();
void Adding(int i);
void fillBill(int i);
void calculateDoctorEarn();
void medicineEarn();
void totalEarning();
void bedQuery();

struct date
{
	int day;
	int month;
	int year;
};
struct details
{
	char name[30];
	char disease[20];
	int age;
	int gender;
	struct date mfg;
	int emergency;
	char Doctor[30];
	int drFees;
	int medicine;
	struct date discharge;
};
struct details patient[100][10];

char diseaseName[15][30] = {
	{"aids"},
	{"flue"},
	{"viral"},
	{"stomach cancer"},
	{"brain hemrdge"},
	{"dyeria"},
	{"food poison"},
	{"hepatitis c"},
	{"hernia"},
	{"headache"},
	{"heart attack"},
	{"blood pressure"},
	{"sugar"},
	{"heat stroke"},
	{"tounsil"}};

int maleBed[25] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int femaleBed[25] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int icu[4] = {0, 0, 0, 0};

struct date search[0];

int a = 0;

int arbaz = 0;
int usama = 0;
int anmol = 0;

int medicine = 0;

int DoctorEarning = 0;
int MedicineEarning = 0;
int TotalEarning = 0;

void bedQuery()
{
	int BookedMaleBed = 0;
	int BookedFemaleBed = 0;
	int BookedIcuBed = 0;
	int i;
	for (i = 0; i < 26; i++)
	{
		if (maleBed[i] == 1)
		{
			BookedMaleBed++;
		}
		if (femaleBed[i] == 1)
		{
			BookedFemaleBed++;
		}
	}
	for (i = 0; i < 4; i++)
	{
		if (icu[i] == 1)
		{
			BookedIcuBed++;
		}
	}
	printf("=============================================================\n");
	printf("        Male Ward    Female Ward    ICU\n");
	printf("=============================================================\n");
	printf("Free     %d           %d             %d        \n", 26 - BookedMaleBed, 26 - BookedFemaleBed, 4 - BookedIcuBed);
	printf("Booked    %d            %d            %d\n", BookedMaleBed, BookedFemaleBed, BookedIcuBed);
	printf("=============================================================\n");
	getch();
	dashboard();
}

void totalEarning()
{

	int i;

	for (i = 0; i <= a; i++)
	{
		if (strcmp(patient[i][5].Doctor, "Dr Arbaz Yousuf") == 0)
		{
			fflush(stdin);
			arbaz += patient[i][7].drFees;
		}
		else if (strcmp(patient[i][5].Doctor, "Dr Usama Ali") == 0)
		{
			fflush(stdin);
			usama += patient[i][7].drFees;
		}
		else if (strcmp(patient[i][5].Doctor, "Dr Anmol Akbar") == 0)
		{
			fflush(stdin);
			anmol += patient[i][7].drFees;
		}
		fflush(stdin);
	}
	for (i = 0; i <= a; i++)
	{

		medicine += patient[i][8].medicine;
	}
	DoctorEarning = arbaz + anmol + usama;
	printf("=============================================================\n");
	printf("Dr.Arbaz  Dr.Usama  Dr.Anmol  Dr. Total  MedicalStore  Total\n");
	printf("=============================================================\n");
	printf("  %d      %d        %d        %d        %d        %d\n", arbaz, usama, anmol, DoctorEarning, medicine, DoctorEarning + medicine);
	printf("=============================================================\n");
	getch();
	dashboard();
}

void medicineEarn()
{

	int i;

	for (i = 0; i < a; i++)
	{

		fflush(stdin);
		medicine += patient[i][8].medicine;
	}
	printf("Earning of Medical Store is %d", medicine);
}

void calculateDoctorEarn()
{

	fflush(stdin);

	if (a == 1)
	{
		if (strcmp(patient[0][5].Doctor, "Dr Arbaz Yousuf") == 0)
		{

			arbaz = arbaz + patient[0][7].drFees;
		}
		else if (strcmp(patient[0][5].Doctor, "Dr Usama Ali") == 0)
		{

			fflush(stdin);
			usama += patient[0][7].drFees;
		}
		else if (strcmp(patient[0][5].Doctor, "Dr Anmol Akbar") == 0)
		{

			fflush(stdin);
			anmol += patient[0][7].drFees;
		}
	}
	int i;

	for (i = 0; i <= a; i++)
	{
		if (strcmp(patient[i][5].Doctor, "Dr Arbaz Yousuf") == 0)
		{
			fflush(stdin);
			arbaz += patient[i][7].drFees;
		}
		else if (strcmp(patient[i][5].Doctor, "Dr Usama Ali") == 0)
		{
			fflush(stdin);
			usama += patient[i][7].drFees;
		}
		else if (strcmp(patient[i][5].Doctor, "Dr Anmol Akbar") == 0)
		{
			fflush(stdin);
			anmol += patient[i][7].drFees;
		}
		fflush(stdin);
	}

	int dr;
	printf("1. Dr Arbaz Yousuf\n2. Usama Ali\n3. Anmol Akbar\n");
	scanf("%d", &dr);
	fflush(stdin);

	if (dr == 1)
	{

		printf("Total Fees of Dr Arbaz Yousuf is %d", arbaz);
	}
	else if (dr == 2)
	{

		printf("Total Fees of Dr Usama Ali is %d", usama);
	}
	else if (dr == 3)
	{

		printf("Total Fees of Dr Anmol Akbar is %d", anmol);
	}
}

void fillBill(int i)
{

	printf("Doctor Fees\n");
	scanf("%d", &patient[i][7].drFees);

	printf("Medicine Fees\n");
	scanf("%d", &patient[i][8].medicine);

	dashboard();
}

void Adding(int i)
{

	printf("Suggest Doctor for your disease\n");
	fflush(stdin);
	int l;
	for (l = 0; l < 15; l++)
	{

		if (strcmp(patient[i][1].disease, diseaseName[l]) == 0)
		{
			fflush(stdin);
			if (l >= 0 && l <= 4)
			{
				printf("Dr Arbaz Yousuf\n");
				strcpy(patient[i][5].Doctor, "Dr Arbaz Yousuf");
				puts(patient[i][5].Doctor);
				fillBill(i);
			}
			else if (l >= 5 && l <= 9)
			{
				printf("Dr Usama Ali\n");
				strcpy(patient[i][5].Doctor, "Dr Usama Ali");
				puts(patient[i][5].Doctor);
				fillBill(i);
			}
			else if (l >= 10 && l <= 14)
			{
				printf("Dr Anmol Akbar\n");

				strcpy(patient[i][5].Doctor, "Dr Anmol Abkar");
				puts(patient[i][5].Doctor);
				fillBill(i);
			}
		}
	}
	fflush(stdin);
}

void emergency()
{
	//	int icu[3]={0,0,0,0};
	int counting = 0;
	int i;
	fflush(stdin);
	for (i = 0; i < 4; i++)
	{
		if (icu[i] == 0)
		{
			counting++;
			fflush(stdin);
		}
	}
	if (counting == 0)
	{
		printf("There's no Bed Available in ICU");
	}
	else
	{
		printf("There's %d Bed Available on ICU\n ", counting);
		printf("Bed is Reserved For Patient: %s", patient[a][1].name);
		for (i = 0; i < 4; i++)
		{
			if (icu[i] == 0)
			{
				icu[i] = 1;
				a++;
				dashboard();
			}
		}
	}
}

void BedBooked()
{

	if (patient[a][3].gender == 1)
	{

		int counting = 0;
		int i;
		fflush(stdin);
		for (i = 0; i < 26; i++)
		{
			if (maleBed[i] == 0)
			{
				counting++;
				fflush(stdin);
			}
		}
		if (counting == 0)
		{
			printf("There's no Bed Available in Male Ward\n");
		}
		else
		{
			printf("There's %d Bed Available on Male Ward \n", counting);
			printf("Bed is Reserved For Patient: %s", patient[a][0].name);
			for (i = 0; i < 26; i++)
			{
				if (maleBed[i] == 0)
				{
					maleBed[i] = 1;
					a++;
					dashboard();
				}
			}
		}
	}
	else
	{
		int counting = 0;
		int i;
		fflush(stdin);
		for (i = 0; i < 26; i++)
		{
			if (femaleBed[i] == 0)
			{
				counting++;
				fflush(stdin);
			}
		}
		if (counting == 0)
		{
			printf("There's no Bed Available in Female Ward");
		}
		else
		{
			printf("There's %d Bed Available on Female Ward \n", counting);
			printf("Bed is Reserved For Patient: %s \n", patient[a][0].name);
			for (i = 0; i < 26; i++)
			{
				if (femaleBed[i] == 0)
				{
					femaleBed[i] = 1;
					a++;
					dashboard();
				}
			}
		}
	}
}

void searched()
{

	printf("Search By Date \n \n");
	printf("Enter a Date (dd-mm-yyyy)");
	scanf("%d-%d-%d", &search[0].day, &search[0].month, &search[0].year);

	int i = 0;

	int flag;

	while (i <= a)
	{
		if (search[0].day == patient[i][4].mfg.day && search[0].month == patient[i][4].mfg.month && search[0].year == patient[i][4].mfg.year)
		{

			fflush(stdin);
			printf("Patient Name: %s \n", patient[i][0].name);
			printf("Disease: %s \n", patient[i][1].disease);
			printf("Age: %d \n", patient[i][2].age);
			printf("Gender: %d\n", patient[i][3].gender);
			printf("Created at: %d-%d-%d\n\n", patient[i][4].mfg.day, patient[i][4].mfg.month, patient[i][4].mfg.year);
			printf("It is a Right Patient? \n1. Yes \n2. No \n:");
			scanf("%d", &flag);
			if (flag == 1)
			{
				int set;
				printf("\nCompletely Searched \n 1. Suggest Doctor \n2. Show Details");
				scanf("%d", &set);
				if (set == 1)
				{
					fflush(stdin);
					Adding(i);
					break;
				}
			}
			else
			{
				i = i + 1;
			}
		}
		else
		{
			i = i + 1;
		}
		if (!flag == 1)
		{
			printf("There's no data of this data");
			printf("\n");
			dashboard();
		}
	}
}

void addPatient()
{

	printf("\nEnter Patent Name: ");
	scanf("%s", &patient[a][0].name);
	fflush(stdin);
	printf("Enter Patient Disease: ");
	scanf("%s", &patient[a][1].disease);
	fflush(stdin);
	printf("Enter Patient Age: ");
	scanf("%d", &patient[a][2].age);
	fflush(stdin);
	//		Check Patient is child so asks about who is stay with him/her
	if (patient[a][2].age < 11)
	{
		fflush(stdin);
		printf("Child Stay With \n 1. Male \n 2. Female \n");
		scanf("%d", &patient[a][3].gender);
	}

	//		otherwise Patient is not child
	else
	{
		fflush(stdin);
		printf("Enter Patient Gender \n 1. Male \n 2. Female \n");
		scanf("%d", &patient[a][3].gender);
	}
	fflush(stdin);
	printf("date(dd-mm-yyyy): \n");
	scanf("%d-%d-%d", &patient[a][4].mfg.day, &patient[a][4].mfg.month, &patient[a][4].mfg.year);
	fflush(stdin);

	//		printf("%s",patient[a][0].name);
	//		printf("%s",patient[a][1].disease);
	//		printf("%d",patient[a][2].age);
	//		printf("%d",patient[a][3].gender);
	//		printf("%d-%d-%d", patient[a][4].mfg.day, patient[a][4].mfg.month, patient[a][4].mfg.year);

	printf("Emergency \n 1. Yes \n 2. No ");
	scanf("%d", &patient[a][5].emergency);
	fflush(stdin);
	if (patient[a][5].emergency == 1)
	{
		fflush(stdin);
		emergency();
	}
	else
	{
		fflush(stdin);
		BedBooked();
	}
}

void dashboard()
{
	//	Asking About menu

	fflush(stdin);
	char index;
	printf("\n");
	printf("=============================================================\n");
	printf("\n1. Add Patient \n2. Search \n3. Doctor Earn\n4. Medicine Earn\n5. Total Earning \n6. Beds Query\n0. Exit");
	scanf("%c", &index);
	printf("=============================================================\n");
	printf("\n");

	fflush(stdin);
	//	Query Process
	if (index == '1')
	{

		addPatient();
	}
	else if (index == '2')
	{
		if (a == 0)
		{
			printf("Sorry First Add Patient");
			addPatient();
		}
		else
		{
			searched();
		}
	}
	else if (index == '3')
	{
		if (a == 0)
		{
			printf("Sorry First Add Patient");
			addPatient();
		}
		else
		{
			calculateDoctorEarn();
		}
	}
	else if (index == '4')
	{
		if (a == 0)
		{
			printf("Sorry First Add Patient");
		}
		else
		{
			medicineEarn();
		}
	}
	else if (index == '5')
	{

		totalEarning();
	}
	else if (index == '6')
	{

		bedQuery();
	}
	else if (index == '7')
	{
		exit(0);
	}
}

void main()
{
	fflush(stdin);
	printf("Welcome \nHospital Management Sytem \n");
	dashboard();
}
