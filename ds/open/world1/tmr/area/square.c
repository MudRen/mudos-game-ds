// Room: /u/t/tmr/area/square.c

inherit ROOM;

void create()
{
        set("short", "�p�s��");
        set("long", @LONG
�@�y��󫰤������p�s���A�s�������Ӥj�������ѵ��H�ܤ��ΡA�_��
�O�y����A���F�h�O�q�����a�W�ӡu�¤Ѵ�v�A���֪��ȫȱq�F�䨫�ӡA
�ѥL���y�W��ߡB�g�ߪ����A�A���T���}�u�¤Ѵ�v���Ӵ��C������N
�s�����F���f�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"mstart",
  "north" : __DIR__"wbridge",
  "south" : __DIR__"street4",
  "east" : __DIR__"day_lake",
]));
        set("objects", ([ /* sizeof() == 1 */
          __DIR__"npc/obj/pot" : 1,
//       "/open/world1/jangshow/mage":1,
  __DIR__"npc/too":1 ,
  __DIR__"npc/uo":1 ,
  "/open/world1/cominging/area/npc/dove":4,
        ]));
        set("outdoors","land");
    set("light",1);
        set("no_clean_up", 0);

        setup();

}
