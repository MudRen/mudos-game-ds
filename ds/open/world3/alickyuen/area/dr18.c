// Room: /u/a/alickyuen/area/dr18.c

inherit ROOM;

void create()
{
	set("short", "ST�CHospital�ICorridor");
	set("long", @LONG
�o�̴N�O�q���f�Ъ����Y�A�ҥH�A�i�H�����@�h���Ө��h�A���o���i
�}��C�Ӧ��ǯf�H�b���@�h�e�J�f�СA��M���Ǥ��P�żƪ��f�Шѯf�H��
�ܡA��|�o�줣�P�żƪ��A�ȡC
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"dr17",
  "east" : __DIR__"dr19",
"north" : __DIR__"dr21",
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
