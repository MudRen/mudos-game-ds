inherit ROOM;
void create()
{
        set("short", "�߮���H��");
        set("light",1);
        set("long", @LONG
�o�̴N�O���񹣦W���߮���H��F�A�A�����Ǧ��\�h���H�Z�h�̥��b
��ѡA�]�����b�m�C�A�ݼˤl�ӭӳ��Z�N���j�A���C�ӤH�����e�i���A
�����]���O�m�Z���H�A�L�����ӳ��|�ܴL�q�A�C
LONG
        );
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"map_16",
  "east" : __DIR__"map_17",
  "southwest" : __DIR__"map_11",
]));
    set("objects",([
       __DIR__"npc/gin" : 1,
       __DIR__"npc/shun" : 1,
       __DIR__"npc/wu" : 1,
    ]) );
          set("outdoors","land");
          set("no_clean_up", 0);
 setup();
        replace_program(ROOM);
}
