// Room: /u/t/truewind/Minetown/area/minetown1.c

inherit ROOM;

void create()
{
	set("short", "�q����");
	set("long", @LONG
�A���ת��i�J�q���A�o�{���W���ӦۦU�P�y���q�u���b��B����
�A�C�@�Ӧ��G���Y���ҫ䪺�ҼˡC�ӥ|�B���f�����q�l�b��(Camp)�l
�ޤF�A���`�N�C�o�ǳ��O���q�u�𮧪��b�סA��M�A�]�i�H�𮧡A��
�L�𮧥i�O�n�I�O���C
LONG
	);
	set("no_clean_up", 0);
	set("valid_startroom", 1);
        set("map","hotel");
	set("outdoors","land");
	set("objects", ([
        __DIR__"npc/robotwaiter" : 1,
]));

	set("item_desc", ([ /* sizeof() == 1 */
  "camp" : "�q�u�̥Ψӧֳt��_��O���q�l�b�סA���q�Ӧ۪Ů𤤪��L�z�q���l�C\n",
]));
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"minetown2",
  "north" : __DIR__"minetown",
  "south" : __DIR__"minetown3",
  "enter" : __DIR__"minetownhotel",
]));
 	setup();
}

int valid_leave(object me, string dir)
{
        if( dir!="enter" )return ::valid_leave(me, dir);

        if( dir=="enter" && me->query_temp("mine/tent") <=0 || !me->query_temp("mine/tent") )
                return notify_fail("�A�٨S���I�������F�I\n");

        return ::valid_leave(me, dir);
}
