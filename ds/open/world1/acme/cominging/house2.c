inherit ROOM;

void create()
{
	set("short", "�D��");
	set("long", @LONG
�o�̬O���`�����ǤH�B�m���a��A�b�o�̦��\�h�����H�Ψ�A�N
���O���Y�ԡB�K�@�B�M�O�����@���ѥ��A�ݨӦb�o�̥ǤH��l�ä����
���n�L�A�����w���ѳQ��X�ӫ����A�����W�U�h�W�u�O�����X�ӡA�b�o
�]�����󤤪��K���A�M���Ψӧ��H������A�O�H�ݨ�F���H��Ÿ�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"path5",
]));
	set("no_clean_up", 0);
	set("item_desc",([
  "���Y��" : "�@�Ӷǩ_�H���]�C�ѱ`�ϥΪ��u��A�@�����Y�Ե��������A�̧ǥѥǸo���n�a���šA�W���٪g�F�@�I�I����C\n",
  "�K�@" : "���K�һs�����@�l�A�W�����@�������K�ġA�Y�O�Q����F�A�w���L�k�������Ͳ��C\n",
  "�O��" : "�����˪��@���K�A�`�`�Ψӫ����D�Ǥ��ΡA�]���ӹL���r�A�`�`���O�b���ݦ��}�ɤ~�Ϊ���C\n",
"�K��" : "�Q�j�ŦD�����@�ج��r����k�A�Ψӧ��ǤH��������ݡA���H�`�h���w�F�L�h�A�]�������a��O���g����A�ҥH�|�PĲ�}�h�C\n",
]));
        set("light",1);
	setup();
	replace_program(ROOM);
}
