inherit ROOM;

void create()
{
        set("short", "�Z����");
        set("long", @LONG
�o�̬O�䳣�ө��󤤪��Z�����A�����f�W�豾�ۨ��M�C�A���̫h�O�\���F
���̮̪��M�C�Z���A�䤤�����٬O�A�����S���L���A���̪��ͷN�ܦn�A���ץ���
�B�Z�̡B�U��U�~���|��o��ӬD��ǪZ���C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"east" : __DIR__"room7",  
  "west" : __DIR__"room4", 
  "south": __DIR__"room8",
  //"north": __DIR__"room4", 
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
}


