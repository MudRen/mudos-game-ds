inherit ROOM;
void create()
{
        set("short", "�y������f");        
        set("long",@LONG
�o�̬O�f������f�����B�A�̵M�S������j��A�y������������
�̦b�o�̨��Ԫ��u�@�ۡA�L�̨Өӥh�h����z����H�ηǳƥX���A�o�O
�L�̩ү�o���̤j�O�q���ɭԡA�b�o�̨C�ӤH���Q���V�O�A�L�̲`���n
�Q���n�ͬ��N�n�u�@�A����O�@�����y�C
LONG
        );
        set("exits", ([
   "east" : __DIR__"se9", 
  "south" : __DIR__"se1",
   "northwest" : __DIR__"se11", 
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}






