inherit ROOM;

void create()
{
        set("short", "���H�P�}");
        set("long", @LONG 
�o�̪����[�A�b�o�̧󦨤@��A�Ҧ����F�賣�\�W�F�զ⪺�F
�l�A�@�����ժ�����A�b�A�ߤ��L�U�����n���L�H�A�B�����٦���
�@���j���y���Y�z�A�����D�O������Ϊ��C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room7", 
  "north" : __DIR__"room9",
]));
        set("light",1);
set("item_desc",([
"���Y":"�����e�����n���o������ۡA�Z�}�G���I�H\n",
]) );

        set("no_clean_up", 0);

        setup();
}
