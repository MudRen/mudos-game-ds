inherit ROOM;
void create()
{
        set("short","�j��W");
        set("long",@LONG
�A����F�j��W���ӡA�o�̬ݨӪK���Z�K�A�ӥB�j��̳s���۳s���_�A
���A���I�����D�q�󨫰_�A���L�j�쳻�ݶǨө_�S���n�A�ӥB�o�ǥj����G
�Q����F��O�@�ۡA���𤣷|�Q���j�P�A���L�o�W�����ͪ��ݨӤ��Ӥ͵��C
LONG
        );
        set("exits", ([
  "east" : __DIR__"stn2",
  "down" : __DIR__"t18",
]));
        set("no_clean_up", 0);
        set("light",0);
        setup();
        replace_program(ROOM);
}










