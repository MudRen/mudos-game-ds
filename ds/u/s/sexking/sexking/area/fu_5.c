#include <ansi.h>
inherit ROOM;
string look_string();
void create()
{
  set ("short", HIG"�ʦL��L"NOR);
  set ("long", @LONG
�A�@����o�̡A�ݨ�F���[�D�Z�����H�A��B�i���j�p���@
���ѵM��L�A���H�����[���A���T�P�Ĥj�۵M�������A�ǻ����o
�̦������i��ĳ���Ʊ��A�İ_�F�A�_�I���믫�A���ߪ����ļ���
�w�g�}�l�m�˰_�ӡA�A�D�D���աA�Q�n�}���o�ӳ��˴˪����D�C
LONG
);
        set("light",1);
        set("no_clean_up", 0);
        set("outdoors","land");
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"fu_7",
  "east" : __DIR__"fu_3",
  "west" : __DIR__"fu_4",
  "south" : __DIR__"fu_2",
  ]));
        setup();
}
