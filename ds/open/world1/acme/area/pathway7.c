// Room: /u/a/acme/old_area/pathway7.c
inherit MOBROOM;
void create()
{
	set("short", "�p�|");
	set("long", @LONG
�A�uı�o�o�̳��˴˪��A�������ΪA�A�����i�Hť�������b�p�s�A
���e��M�@�s�¦⽿�����A�Y�W���h�A���n��A�i�H�ݨ즳�@��������
�}���Τl�C
LONG
	);
	set("no_clean_up", 0);
        set("chance",70);
        set("mob_amount",3);    //�h�̦h�X�{�T�өǪ�.
        set("mob_object",({     //�]�w�Ǫ��ɦW.
            __DIR__"npc/bat",
        }) );
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"h1",
  "west" : __DIR__"pathway5",
]));
	setup();
}
