inherit ROOM;
void create()
{
          set("short","�K������");
          set("long",@LONG
�ߤ@�@���q���D�����K���N�O�ة�o�Ө����̭��A�C�ѳ����ܦh�f��
�M�H�̳��g�o�̩��ӡC�i��ѩ�f�~�j�h�H�q�����D�A�ϱo�o�̦��@�ǸH
�����q���b�a�W�A�ӳq�L���H��F�U�h�A�ϱo�a���H�W�F�q������m�C�A
�{�b�i�J�Y�i�����K���C
LONG
           );
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
          "westdown" : __DIR__"digging_street4",
          "enter"  : __DIR__"train",
	]));
           setup();
}