// This is a room made by roommaker.
inherit ROOM;
void create()
{
set("short", "�F�a");
set("long", @LONG
�A�����b�@���n�n���F�a�W�A��W�h���C�@�B���d�U�F�@�ӫܲ`���}�L�C
���䦳�@�Ӥj���Y�A�Q�����ơA�i�H���H���W�h�𮧡C�\�h���ߴ����b�F�l��
�A�A�ݨ즳�@�ӦǶ��۶��y�������ߤQ���n�ݡA�Ԥ���h�ݤF�Ⲵ�C
LONG
);
set("exits", ([ 
  "west" : __DIR__"sea2",
  "east" : __DIR__"sea4",
  "south" : __DIR__"sea10",
]));
set("no_clean_up", 0);
set("outdoors",1);
setup();
//replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
 if( dir=="south")
 {
  return notify_fail("�����٨S���}���!!\n");
 }
 return ::valid_leave(me, dir);
}