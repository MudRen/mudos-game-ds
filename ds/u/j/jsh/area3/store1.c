inherit ROOM;

void create()
{
        set("short", "�B�F����");
        set("long", @LONG
�o�̬O�B�F�����A�s���������A��곣�O�ѭ��աA�L�̤j�h���O
�B�F�����~���A�b�����������@�Ƿs��o�X�Ӫ��F��A���L�����~
�����ٶQ�A�����o�઺�F��A���O�u����ơC
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"store3", 
  "west" : __DIR__"store2", 
  "east" : "/open/world1/cominging/area/bsouth3",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"sellman1" : 1,
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

