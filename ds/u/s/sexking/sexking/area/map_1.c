inherit ROOM;
void create()
{
        set("short", "�߮���H��J�f");
        set("light",1);
        set("long", @LONG
�o�̬O�߮���H�窺�J�f�A���ɳ��|����T�Ӧu�æb�o�̦u�@�H���U�@
�A�A���̭��ˤF�@�U�A�o�{�̭���B���O�b�O�A��M�O�Z�h�̴Ϯ����a
�A�]ť��F�M�C�������n���I�i���o�̤��O�@�Ӵ��q���a��C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"map_2",
  ]));
    set("objects",([
       __DIR__"npc/ching" : 1,
       __DIR__"npc/guard" : 2,
    ]) );
         set("outdoors","land");
         set("no_clean_up", 0);
 setup();
        replace_program(ROOM);
}
