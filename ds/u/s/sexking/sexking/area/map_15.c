inherit ROOM;

void create()
{
        set("short", "�ۼ��D��");
     set("light",1);
        set("long", @LONG
�o�̬O�饻�ۼ��̤��ɸ��l���a��A�a�O�W�e���@�ӥզ⪺����A
�ݼˤl���ӬO���ɮɪ����ɽu�C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"map_14",
 ]));
        set("objects",([
       __DIR__"npc/man" : 2,
    ]) );
        set("no_clean_up", 0);
 setup();
        replace_program(ROOM);
}
