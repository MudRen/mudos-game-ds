// This is a room made by roommaker.
inherit ROOM;
void create()
{
set("short", "�F�a");
set("long", @LONG
�A���p�߽��F�@�Ӥj���Y, �h���t�I�s�X�n��! ���䤣�����a�観�Ӱ�
��, �M���񪺦a�Τ���_����o�Q�������ءC�F��O�@���I�Y, ���G�i�H�q��
�j�����̩��ݡC���c������q�F�_�褣�_���j�L��, �A�}�l�Ҽ{�O���O�Ө��U
�h�C
LONG
);
set("exits", ([ 
  "eastdown" : __DIR__"sea17",
  "north" : __DIR__"sea6",
  "west" : __DIR__"tower",
  "south" : __DIR__"sea4",
]));
set("no_clean_up", 0);
set("outdoors",1);
setup();
//replace_program(ROOM);
}
/*
int valid_leave(object me, string dir)
{
 if( dir=="eastdown")
 {
  if(!wizardp(me)) return notify_fail("�����٨S���}���!!\n");
 } 
 return ::valid_leave(me, dir);
}
*/
