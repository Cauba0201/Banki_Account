#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//user
struct user {
	char phone[50];
	char acc[50];
	char password[50];
	float balance;
};


int main(){
	struct user usr, usr1;
	FILE *fp;
	char filename[50], phone[50], pword[50];
	int option, choise;
	char cont = 'y';
	float amount;
	
	printf("\nBan muon lam gi?");
	printf("\n\n1. Danh ky tai khoan.");
	printf("\n2. Danh nhap tai khoan.");
	
	printf("\n\nHay lua chon yeu cau ban muon: \t");
	scanf("%d",&option);
	
	
	//1 dang ky
	if(option == 1){
		system("cls");
		printf("Moi ban nhap ten tai khoan: \t");
		scanf("%s",usr.acc);
		printf("Moi nhap so dien thoai: \t");
		scanf("%s",usr.phone);
		printf("Moi nhap mat khau: \t");
		scanf("%s",usr.password);
		usr.balance = 0;
		strcpy(filename,usr.phone);
		fp = fopen(strcat(filename,".txt"),"w");
		fwrite(&usr, sizeof(struct user),1,fp);
		if(fwrite != 0){
			printf("\n\nDang ky thanh cong");
		} else {
			printf("\n\nCo gi do khong dung vui long thu lai");
		}
		fclose(fp);
	}
	
	// 2 dang nhap
	if(option == 2){
		system("cls");
		printf("\nNhap so dien thoai: \t");
		scanf("%s",phone);
		printf("\nMat khau: \t");
		scanf("%s",pword);
		strcpy(filename,phone);
		fp = fopen(strcat(filename,".txt"),"r");
		if(fp == NULL){
			printf("\nSo dang nhap khong dung!");
		} else {
			fread(&usr, sizeof(struct user),1,fp);
		fclose(fp);
		if(!strcmp(pword,usr.password)){
			printf("\n\t Welcome, %s",usr.phone);
			while(cont == 'y'){
				system("cls");
				printf("\nAn phim 1 de kiem tra tai khoan");
				printf("\nAn phim 2 de gui them tien");
				printf("\nAn phim 3 de rut tien");
				printf("\nAn phim 4 de chuyen tien");
				printf("\nAn phim 5 de doi mat khau");
				printf("\n\nLua chon cua ban: ");
				scanf("%d",&choise);
				switch(choise){
					case 1:
						printf("\nSo du hien tai cua ban la: %.2f VND",usr.balance);
					break;
					case 2:
						printf("\nVui long nhap so tien: \t");
						scanf("%f", &amount);
						usr.balance += amount;
						fp = fopen(filename,"w");
						fwrite(&usr,sizeof(struct user),1,fp);
						if(fwrite != NULL) printf("\nGiao dich thanh cong");
						fclose(fp);
						break;
					case 3:
						printf("\nVui long nhap so tien: \t");
						scanf("%f", &amount);
						usr.balance -= amount;
						fp = fopen(filename,"w");
						fwrite(&usr,sizeof(struct user),1,fp);
						if(fwrite != NULL) printf("\nBan da rut thanh cong %.2f", amount);
						fclose(fp);
						break;
						
					case 4:
						printf("\nVui long nhap so dien thoai muon gui tien: \t");
						scanf("%s",phone);
						printf("\nNhap so tien ban muon gui: \t");
						scanf("%f",&amount);
						if( amount > usr.balance) printf("\nSo du khong du");
						else{
							strcpy(filename,phone);
							fp = fopen(strcat(filename,".txt"),"r");
							if(fp == NULL){
								printf("\nSo dien thoai chua dang ky");
								return 0;
							}
							fread(&usr1,sizeof(struct user),1,fp);
							fclose(fp);
							fp = fopen(filename,"w");
							usr1.balance +=amount;
							fwrite(&usr1,sizeof(struct user),1,fp);
							fclose(fp);
							
							if(fwrite != NULL){
								printf("\nBan da chuyen tien thanh cong so tien %.2f cho so dien thoai %s",amount,phone);
								strcpy(filename,usr.phone);
								fp = fopen(strcat(filename,".txt"),"w");
								usr.balance -= amount;
								fwrite(&usr, sizeof(struct user),1,fp);
								fclose(fp);
							}
						}
						break;		
					case 5:
						printf("\nNhap mat khau moi: \t");
						scanf("%s",pword);
						fp = fopen(filename,"w");
						strcpy(usr.password,pword);
						fwrite(&usr,sizeof(struct user),1,fp);
						if(fwrite != NULL){
							printf("\nThay doi mat khau thanh cong");
						}
						break;
					default:
						printf("\nKhong co lua chon nao");					
				}				
				printf("\nBan co muon tiep tuc giao dich [y/n]\t");
				scanf("%s",&cont);
			}
		} else {
			printf("\nMat khau khong hop le");
		}
		}		
	}	
	return 0;
}
