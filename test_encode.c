#include<stdio.h>
#include<string.h>
#include"type.h"
#include"encode.h"
#include"decode.h"

int main(int argc ,char *argv[])
{
    EncodeInfo encInfo;
    DecodeInfo decInfo;

    OperationType ret;
    
    if(argc<3)
    {
        printf("USAGE : Encode ----> ./a.out -e <src.bmp> <secret.txt> [stego.bmp]\n");
        printf("USAGE : Decode ---->ego.bmp>\n");
 
        return -1;
    }

    ret=check_operation_type(argv);

    if(ret==e_encode)
    {
           printf("SELECTED ENCODING.\n");

           if(read_and_validate_encode_argc(argv, &encInfo)==e_success)
           {
              printf("READ AND VALIDATE ENCODE ARGS IS SUCCESSFULLY.\n");
           }   
           else
           {
              printf("READ AND VALIDATE ENCODE ARDS IS FAILURE.\n");
              return e_failure;
           }

           if(do_encoding(&encInfo) == e_failure)
           {
              printf("ENCODING FAILURE\n");
              return e_failure;
           }

         printf("ENCODED SUCCESSFULLY\n");
         return e_success;
           
    }
    
    else if(ret == e_decode)
    {
        printf("SELECTED DECODING\n");
         if(read_and_validate_decode_argc(argv, &decInfo)==e_success)
           {
              printf("READ AND VALIDATE DECODE ARGS IS SUCESSFULLY.\n");
           }   
           else
           {
              printf("READ AND VALIDATE DECODE ARGS IS FAILURE.\n");
              return e_failure;
           }

           if(do_decoding(&decInfo) == e_failure)
           {
              printf("DECODING FAILURE\n");
              return e_failure;
           }

           printf("DECODED SUCCESSFULLY\n");
           return e_success;
    }

    else
    {
        printf("UNSUPPORTED OPERATION.\n");
        return e_failure;
    }

    return e_success;

}

OperationType check_operation_type(char *argv[])
{
      if(strcmp(argv[1], "-e")==0)
      {
         return e_encode;
      }
      else if(strcmp(argv[1], "-d")==0)
      {
         return e_decode;
      }
      else
      {
         return e_unsupported;
      }
}

Status read_and_validate_encode_argc(char *argv[], EncodeInfo *encInfo)
{
       if(strstr(argv[2],".bmp") != NULL)
       {
           encInfo->src_image_fname=argv[2];
       }
       else
       {
          printf("SOURCE IMAGE FILE NOT SUPPORTED.\n");
          return e_failure;
       }

       if(strstr(argv[3],".txt") != NULL)
       {
           encInfo->secret_fname=argv[3];
       }
       else
       {
           printf("SECRET MESSAGE FILE NOT SUPPORTED.\n");
           return e_failure;
       }

       if(argv[4] != NULL)
       {
          if(strstr(argv[4],".bmp") != NULL )
          {
              encInfo->stego_image_fname=argv[4];
          }
          else
          {
             printf("STEGO IMAGE FILE NOT SUPPORTED.\n");
             return e_failure;
          }
      }
      else
      {
          encInfo->stego_image_fname="stego.bmp";
      }
      return e_success;
}
Status read_and_validate_decode_argc(char *argv[],DecodeInfo *decInfo)
{
    if(strstr(argv[2],".bmp") != NULL)
    {
        decInfo->stego_image_fname=argv[2];
    }
    else
    { 
         printf("SOURCE IMAGE FILE NOT  TO SUPPORTED.\n");
         return e_failure;
    }

    if(argv[3] != NULL)
    {
        if(strstr(argv[3],".txt") != NULL)
        {
            decInfo->output_fname=argv[3];
        }
        else
        {
            printf("OUTPUT FILE NOT SUPPORTED.\n");
            return e_failure;
        }
    }
    else
    {
        decInfo->output_fname="output";
    }
    return e_success;
}
