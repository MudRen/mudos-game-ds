#include <ansi.h>

inherit ITEM;

string show_long();

void create()
{
	set_name(HIC"��O�j�|�i�ܪO"NOR, ({ "board" }) );
	set("no_get", 1);
	set("no_sac", 1);
	set("value", 0);
	set("long", ""+this_object()->show_long()+"");

	setup();
}

string show_long()
{
	string msg;
/*
�]���^�D�ص������q���D(Quest)�B�z�A�T��H���}�W�D�߰ݩθѵ���
�@�@�@�D�C
*/
	return (@long
���y�O�@�جJ�n���S�q�������N�A���z�S�@�I�I�A�S���äF�@�I�I�A
�o���n�r�_�q���̪��n�_�ߡA�޵o�j�a�l�M����������C���y�]�R��
�T�֩ʡB��ǩʩM���ѩʡA�h�q���y�A�٥i�H�����q���̪����z��O
�M���R��O�C�ѩ�o�����ʯq�B�Ʀh�G�����~�פ���`����O�j�|�N
�|��@�����ʡСy�O���v�v�z�A���C���u�h�p�U�G

�]���^�C���i��ɶ�������ܢ����뢱��ߤW�����ɥ��C
�]���^�O���C���]�S�Ťj���@�W�B�j���|�W�δ��q�ѥ[���C
�]���^�C�����k���G
�@�@�@�@�@�������D�سB�A�M����J���O answer �^�����D�C
�@�@�@�@�@�Ҧp�Ganswer release
�@�@�@�@�@�Y�D�بS�S�O���ܡA���׶����y����z�r�C
�@�@�@�@�@���`�N���������D�ج��עߴ��O�D�C
�]���^��������D�ЦV�Ův Release �d�ߡC 

Write By -Alickyuen@DS- & -Release@DS- on 23/9/2001
long);
}