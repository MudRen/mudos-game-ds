// Room: /d/wiz/jobroom.c

inherit ROOM;

void create()
{
	set("short", "�u�@�i��²����");
	set("long", @LONG
�o�̬O�Ův�̳��i�ۤv�u�@�i�ת�²���ǡM�P�ɤ]�O�j�Ův�줽�t
���ھڡM�p�G�A���u�@���M�̦n�`�`��o�̧�s�A���u�@�i�סM�p�G��
�[�S���ݨ�A���u�@�i�׳��i�M�j�Ův�̷|�H���H�S�ư��ӫ����u�@��
�M�n�O�A���M���z�M�]���i��|�Q���]���w�g���Ův���u�@�ӭ��^��
�a�����C�A�`�N��k�䪺��W�s�K�F�@�i[1;37m�ȱ�(Note)[0m�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/wiz/hall1",
]));
	set("no_clean_up", 0);
set("item_desc",([
  "note":@NOTE

============�u�@�i�׬����O���ϥΤ�k�p�U===============

 �s�W�p��: project   <���D>
 ���i�i��: report    <�p�e�s��> <�i�׳��i���D>
 �\Ū�p��: read      <�p�e�s��>[.<���i�s��>]|new|next
 �R���p��: terminate <�d���s��> 

=======================================================
  
PS.�]���o�ӯd���O���ϥΤ覡���I���Ӥ@��, �ҥH�ڶK�i�ȱ�
�����@�U�ϥΤ�k.
			-�s��(Luky)�q�W.1999.7.24.-
NOTE
,]));

	setup();
	call_other("/obj/board/wizard_j", "???");
	replace_program(ROOM);
}
