// Room: /u/a/acme/area/tnb.c

inherit ROOM;

void create()
{
	set("short", "�ä줺");
     set("light",1);
	set("long", @LONG
�A���B�b���j���ä줺�A����ä쳺�e�o�U�G�H���e�סA�|�P�G���F
�ǹСA���䪺�ç��O���G���ǩǲ��A���`�����b�A�|�P�����۵��L�@���H
���߯ȩM�@�Ǩƪ��C���W�i���X�o�Ӥj�ç��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"h1",
]));
	set("no_clean_up", 0);
      set("item_desc", ([
"�ç��O" : "�A�����V�F�ç��O�A���G���Y�O�Ū��A�����w�i�H��(push)�}���C\n",
"�߯�"  : "�c�K�K�o�O�����H�Ϊ��A�������A�n�ΡH\n",
"�ƪ�"  : "�c�K�K�o�Ǩƪ��O�����H�Ϊ��A�������A�n�ΡH\n",
      ]));

	setup();
}
void init()
{
        add_action("typepush","push");
}
     int typepush(string arg)
{
        object me;
        me=this_player();
        if(arg != "�ç��O") return 0;
        message_vision(
         "$N�������}�F�ç��O�A�ç��O��F�b�Ө��A����X�{�F�@�ӥX�f�C\n"
         ,me);
         set("exits", ([
          "west" : __DIR__"secret",
          "up" : __DIR__"h1",
]));
        return 1;
} 

