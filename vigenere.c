#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

int main (int argc, string argv[])
{

    string key = argv[1];
    bool userInput = true;

    for(int a = 0; a < strlen(argv[1]); a++)
    {
        if(isalpha(key[a]))
        {
            userInput = true;
        }

        else
        {
            userInput = false;
            return 0;
        }

    }


    if(argc == 2 && userInput)
    {
        // c[i] = (p[i] + k[j]) % 26;
        string plainText = get_string("Enter your message : \n");
        int aSize = strlen(plainText);
        int x = 0;

        for(int i = 0; i < aSize; i++)
        {


           if(isalpha(plainText[i]))
           {
                int j = x % strlen(key);

                if(isupper(plainText[i]))
                {
                    int plainASCII = (int)plainText[i];
                    int plainConversion = plainASCII - 65;

                    int keyASCII = 0;
                    int keyConversion = 0;


                    if(isupper(key[j]))
                    {
                        keyASCII = (int)key[j];
                        keyConversion = keyASCII - 65;
                    }

                    else
                    {
                        keyASCII = (int)key[j];
                        keyConversion = keyASCII - 97;
                    }

                    int c = (plainConversion + keyConversion) % 26;
                    char output = c + 65;
                    printf ("%c",output);
                    x++;



                }

                if(islower(plainText[i]))
                {
                    int plainASCII = (int)plainText[i];
                    int plainConversion = plainASCII - 97;

                    int keyASCII = 0;
                    int keyConversion = 0;


                    if(isupper(key[j]))
                    {
                        keyASCII = (int)key[j];
                        keyConversion = keyASCII - 65;
                    }

                    else
                    {
                        keyASCII = (int)key[j];
                        keyConversion = keyASCII - 97;
                    }

                    int c = (plainConversion + keyConversion) % 26;
                    char output = c + 97;
                    printf ("%c",output);
                    x++;

                }




           }

           else
           {
               printf("%c",plainText[i]);
           }

        }



    }

}
