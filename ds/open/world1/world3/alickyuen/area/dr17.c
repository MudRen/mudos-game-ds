// Room: /u/a/alickyuen/area/dr17.c

inherit ROOM;

void create()
{
	set("short", "ST�CHospital�ICorridor");
	set("long", @LONG
�o�جO�T�Ӫ��F��A�@���e�諸���Y�C�A�ݨ��g�`���@���@�h�����
�b�o���Ө��h�A�S�Ϊ̬O�@�ǯf�H���F�X�Ӵ��B�C�t�~�A�b�o�ݨ쨫�Y��
�G�Ǧ��@�Ǫ��A�O�Ψӳq���f�Ъ��C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"dr16",
  "east" : __DIR__"dr18",
"north" : __DIR__"dr22",
]));
        set("item_desc", ([ /* sizeof() == 1 */
  "��" : "�o�O�@�D�|�۰ʶ}�����C\n",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
}

int valid_leave(object me, string dir)
{
        if( dir=="north" ) tell_object(me,"��A���Q���h�}�������ɡA����M�۰ʥ��}�F�A��ӬO�@���m�۰ʪ��n�C\n");
        return ::valid_leave(me, dir);
}

