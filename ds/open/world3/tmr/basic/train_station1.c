inherit ROOM;
void create()
{
          set("short","�K������");
          set("long",@LONG
�ߤ@�@���q���D�����K���N�O�ة�o�Ө����̭��A�C�ѳ����ܦh�f��
�M�H�̳��g�o�̩��ӡC�i��ѩ�f�~�j�h�H�q�����D�A�ϱo�o�̦��@�ǸH
�����q���b�a�W�A�ӳq�L���H��F�U�h�A�ϱo�a���H�W�F�q������m�C
LONG
           );
     set("light",1);
	set("exits", ([ /* sizeof() == 1 */
          "westdown" : __DIR__"digging_street4",
	]));
	set("objects",([
          __DIR__"npc/driver":1,
//            __DIR__"obj/dinkey":1,
	]));
	set("no_kill",1);
	set("no_magic",1);
	set("no_clean_up", 0);
	setup();
}
