#include <stdio.h>
#include <stdlib.h>


int toplamPartiMvHesaplama(int toplamPartiMvSayisi[],int partiSayisi,int mvSayisi[])
{
    int i;
         for(i=0;i<partiSayisi;i++)
                    {
                        toplamPartiMvSayisi[i] += mvSayisi[i];
                    }
                    return toplamPartiMvSayisi[partiSayisi];

}
void iktidarBelirle(int toplamPartiMvSayisi[],int partiIsim[],int partiSayisi)
{
    int i,j,gecici,gecici2;
                    for(i=0; i<partiSayisi-1; i++)
                    for(j=0; j<partiSayisi-1; j++)
                    if( toplamPartiMvSayisi[j]<toplamPartiMvSayisi[j+1] )
                    {
                    gecici = toplamPartiMvSayisi[j];
                    toplamPartiMvSayisi[j] = toplamPartiMvSayisi[j+1];
                    toplamPartiMvSayisi[j+1] = gecici;


                    gecici2=partiIsim[j];
                    partiIsim[j]=partiIsim[j+1];
                    partiIsim[j+1]=gecici2;



                    }

                    printf("Iktidar Partisi: %c Partisi\n", (char)partiIsim[0]);
                    printf("Ana Muhalefet Partisi: %c Partisi", (char)partiIsim[1]);
}

int toplamOyHesapla(int toplamOySayilari[],int oySayisi[],int partiSayisi)
{
    int i;
                for(i=0;i<partiSayisi;i++)
                {
                    toplamOySayilari[i] += oySayisi[i];
                }

}


int main()

{
        int partiSayisi,plakaKodu,mvKontenjani,i,j,gecici,gecici2,gecici3,gecici4,gecici5,gecici6,gecici7;
        int t = 0,Birincilik=1;
        float gecerliOy  = 0,toplamOy=0, toplamMvSayisi=0;
        float oyYuzde = 0,mvYuzde = 0;


        int ch = 65;

do{

        printf("Secime katilan parti sayisini giriniz:(1-15)");
        scanf("%d",&partiSayisi);

        }
        while(partiSayisi<=0 || partiSayisi>15);
        printf("\n");

        int partiIsim[partiSayisi];
        int oySayisi[partiSayisi];
        int mvSayisi[partiSayisi];
        int mvOySayisi[partiSayisi];
        int toplamOySayisi[partiSayisi];
        int toplamPartiMvSayisi[partiSayisi];
        int ilBirinci[partiSayisi];
        int dusukMvilSayisi[partiSayisi];
        int toplamOySayilari[partiSayisi];



        for(i=0;i<partiSayisi;i++)
        {


            partiIsim[i] = ch;
            ch++;
        }

         for(i=0;i<partiSayisi;i++)
                {
                    toplamPartiMvSayisi[i] = 0;
                    ilBirinci[i] = 0;
                    dusukMvilSayisi[i] = 0;
                    toplamOySayilari[i] = 0;
                }



        do{
                printf("Ilin plaka kodunu giriniz:");
                scanf("%d",&plakaKodu);

                if(plakaKodu== 0){


                        printf("Turkiye Geneli:\n");
                        printf("Milletvekili Kontenjani:%.0f\n",toplamMvSayisi);
                        printf("Toplam Oy Sayisi:%.0f\n",toplamOy);
                        printf("\n");

                                printf("\t");
                                printf("       Oy Say\t");
                                printf(" Oy Yuzde\t");
                                printf("Toplam Mv Say\t");
                                printf(" Mv Yuzde\t ");
                                printf("Il 1.lik Say\t ");
                                printf(" 0 Mv Say\n");
                                printf("\t");
                                printf("      ---------\t");
                                printf(" ---------\t");
                                printf(" ---------\t");
                                printf("---------\t");
                                printf("---------\t");
                                printf("---------\t");
                                printf("\n");



                        for(i=0;i<partiSayisi;i++)
                        {
                                printf("%c partisi: \t", (char)partiIsim[i]);
                                printf("%d \t ",toplamOySayilari[i]);
                                oyYuzde = (toplamOySayilari[i] * 100) / toplamOy;
                                printf("%.2f \t  ",oyYuzde);
                                printf("           %d \t  ",toplamPartiMvSayisi[i]);
                                mvYuzde = (toplamPartiMvSayisi[i] * 100) / toplamMvSayisi;
                                printf("         %.2f  \t ",mvYuzde);
                                printf("   %d  \t ",ilBirinci[i]);
                                printf("            %d\n",dusukMvilSayisi[i]);




                        }

                    iktidarBelirle(toplamPartiMvSayisi,partiIsim,partiSayisi);

                        break;

                }
                do{
                printf("Milletvekili Kontenjanini giriniz:(1-20)");
                scanf("%d",&mvKontenjani);
                }
                while(mvKontenjani<=0 || mvKontenjani>20);


                toplamMvSayisi  += mvKontenjani;

                for(i=0;i<partiSayisi;i++)
                {
                    mvSayisi[i] = 0;

                }

                gecerliOy = 0;


                for(i=0;i<partiSayisi;i++)
                {

                    printf("%c Partisinin Oy Sayisini Giriniz:",(char)partiIsim[i]);
                    scanf("%d",&oySayisi[i]);

                      gecerliOy += oySayisi[i];


                }
                toplamOy+= gecerliOy;

                toplamOyHesapla(toplamOySayilari,oySayisi,partiSayisi);


                printf("\n");
                printf("Il plaka Kodu:%d\n",plakaKodu);


                printf("Milletvekili Kontenjani:%d\n",mvKontenjani);
                printf("Gecerli Oy Sayisi:%.0f\n",gecerliOy);



                    for(i=0; i<partiSayisi-1; i++)
                    for(j=0; j<partiSayisi-1; j++)
                    if( oySayisi[j]<oySayisi[j+1] )
                    {
                    gecici = oySayisi[j];
                    oySayisi[j] = oySayisi[j+1];
                    oySayisi[j+1] = gecici;

                    gecici2 = partiIsim[j];
                    partiIsim[j] = partiIsim [j+1];
                    partiIsim[j+1] = gecici2;

                    gecici3 = mvSayisi[j];
                    mvSayisi[j]  = mvSayisi[j+1];
                    mvSayisi[j+1]  =  gecici3;

                     gecici5 = ilBirinci[j];
                     ilBirinci[j] = ilBirinci[j+1];
                      ilBirinci[j+1] = gecici5;

                      gecici6 =  dusukMvilSayisi[j];
                      dusukMvilSayisi[j] = dusukMvilSayisi[j+1];
                      dusukMvilSayisi[j+1] = gecici6;

                    }

                    ilBirinci[0] += 1;


                        for(i=0;i<partiSayisi;i++)
                            {
                                mvOySayisi[i] = oySayisi[i];


                            }

                    for(;;){
                        mvOySayisi[0] = mvOySayisi[0]/2;
                        mvSayisi[0] += 1;
                        mvKontenjani--;




                        for(i=0; i<partiSayisi-1; i++)

                        for(j=0; j<partiSayisi-1; j++)
                        {
                        if( mvOySayisi[j]<mvOySayisi[j+1] )
                        {
                        gecici = oySayisi[j];
                        gecici4 = mvOySayisi[j];
                        gecici2 = partiIsim[j];
                        gecici3 = mvSayisi[j];
                        oySayisi[j] = oySayisi[j+1];
                        mvOySayisi[j] = mvOySayisi[j+1];
                        partiIsim[j] = partiIsim [j+1];
                        mvSayisi[j]  = mvSayisi[j+1];
                        oySayisi[j+1] = gecici;
                        mvOySayisi[j+1] = gecici4;
                        partiIsim[j+1] = gecici2;
                        mvSayisi[j+1]  =  gecici3;

                        }
                        }


                    if(mvKontenjani == 0)
                        break;
                    }



                   for(i=0; i<partiSayisi-1; i++)
                    for(j=0; j<partiSayisi-1; j++)
                    if( oySayisi[j]<oySayisi[j+1] )
                    {
                    gecici = oySayisi[j];
                    gecici2 = partiIsim[j];
                    gecici3 = mvSayisi[j];

                    oySayisi[j] = oySayisi[j+1];
                    partiIsim[j] = partiIsim [j+1];
                    mvSayisi[j]  = mvSayisi[j+1];

                    oySayisi[j+1] = gecici;
                    partiIsim[j+1] = gecici2;
                    mvSayisi[j+1]  =  gecici3;


                    }


                      for(i=0;i<partiSayisi;i++){

                            if(mvSayisi[i]==0)
                            {
                                dusukMvilSayisi[i] +=1;
                            }


                    }


                    printf("\t");
                    printf("        Oy Say\t");
                    printf("        Oy Yuzde\t");
                    printf("Mv Say\t");
                    printf("\n");
                    printf("\t");
                    printf("      ---------\t");
                    printf("      ---------\t");
                    printf("      ---------\t");
                    printf("\n");
                    for(i=0;i<partiSayisi; i++){

                    printf("%c partisi:\t ", (char)partiIsim[i]);
                    printf("%d \t \t",oySayisi[i]);
                    oyYuzde = (oySayisi[i] * 100) / gecerliOy;
                    printf("%.2f\t \t",oyYuzde);
                    printf("%d\n",mvSayisi[i]);



                    }

                    printf("\n");




                                for(i=0;i<partiSayisi;i++)
                              {
                                       for(j=0;j<partiSayisi;j++)
                                       {
                                             if(partiIsim[i]<=partiIsim[j])
                                             {

                                                    gecici=partiIsim[i];
                                                    partiIsim[i]=partiIsim[j];
                                                    partiIsim[j]=gecici;

                                                    gecici4 = mvSayisi[i];
                                                    mvSayisi[i] = mvSayisi[j];
                                                    mvSayisi[j] = gecici4;

                                                    gecici2 = ilBirinci[i];
                                                    ilBirinci[i] = ilBirinci[j];
                                                    ilBirinci[j] = gecici2;

                                                    gecici3 =  dusukMvilSayisi[i];
                                                    dusukMvilSayisi[i] = dusukMvilSayisi[j];
                                                    dusukMvilSayisi[j] = gecici3;
                                                    }
                                         }
                              }

                    toplamPartiMvHesaplama(toplamPartiMvSayisi,partiSayisi,mvSayisi);


        }
            while(1);



    return 0;
}
