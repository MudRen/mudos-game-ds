inherit ROOM;

void create()
{
        set("short", "���㩱");
        set("long", @LONG
�o�̬O�䳣�ө��󤤪��Z�����A�����f�W�豾�ۤ@����ޡA�����\�ۦU����
�ҡB����A�Y�w�������A����·�áA²���i�H��@�ժ��]�F�C 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"east" : __DIR__"room7",  
  "west" : __DIR__"room6", 
  //"south": __DIR__"room9",
  "north": __DIR__"room8", 
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
}


