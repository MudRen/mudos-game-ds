inherit ROOM;

void create()
{
        set("short", "���]");
        set("long", @LONG
�o�̬O�@�����ت����]�A���M���O�ܤj���O���C�B�]�Ƴ��ܤ����A�p�G�Aı
�o�֤F�i�H�q�өХ𮧤@�U�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"room8", 
  "west" : __DIR__"room2", 
  "south": __DIR__"room6",
  "north": __DIR__"room4",]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
}


