inherit ROOM;
void create()
{
        set("short", "�y������f");        
        set("long",@LONG
�o�̬O�f������f�����B�A�̵M�S������j��A�y������������
�̦b�o�̨��Ԫ��u�@�ۡA�L�̨Өӥh�h����z����H�ηǳƥX���A�o�O
�L�̩ү�o���̤j�O�q���ɭԡA�b�o�̨C�ӤH���Q���V�O�A�L�̲`���n
�Q���n�ͬ��N�n�u�@�A�F��O�@�����y�C
LONG
        );
        set("exits", ([
   "west" : __DIR__"se10", 
  "south" : __DIR__"se2",
   "northeast" : __DIR__"se8", 
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}






