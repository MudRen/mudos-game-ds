inherit ROOM;

void create()
{
        set("short", "�}��M�s�a");
        set("long", @LONG
�o�̬O�����x���s�a�A���M���C�ܯ}�¡A���O���w�o�̪��s���ȤH
    �٬O�|�Ө�o��ӥ��U�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"west" : __DIR__"room7",
  "southeast" : __DIR__"room22",
  //"northeast" : __DIR__"room16",
  "east" : __DIR__"room19",
])); 
        set("objects",([
  __DIR__"npc/room18-boss":1,
]));
        set("light",1);
        setup();
        //replace_program(ROOM);
}

