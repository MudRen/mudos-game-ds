inherit ROOM;
void create()
{
        set("short", "�y������f");        
        set("long",@LONG
�o�̬O�f������f�����f�ϡA�̵M�S������j��A�y������������
�̦b�o�̨��Ԫ��u�@�ۡA�L�̨Өӥh�h����z����H�ηǳƥX���A�o�O
�L�̩ү�o���̤j�O�q���ɭԡA�b�o�̨C�ӤH���Q���V�O�A�L�̲`���n
�Q���n�ͬ��N�n�u�@�A�F��O�@�����y�C
LONG
        );
        set("exits", ([
  "north" : __DIR__"se9",
   "northeast" : __DIR__"se3",
   "west" : __DIR__"se1", 
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}






