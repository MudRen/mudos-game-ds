// wizard_j.c

inherit "/std/jboard";

void create()
{
	set_name("�Ův�u�@�i�׳��i", ({ "job board", "board" }) );
	set("location", "/d/wiz/jobroom");
	set("board_id", "wizard_j");
	set("long",@LONG

�o�O�@�ӯS�����d���O�ѧŮv���i�ۤv���u�@�i�סC
�ϥΤ�k: 

�s�W�p��: project   <���D>
���i�i��: report    <�p�e�s��> <�i�׳��i���D>
�\Ū�p��: read      <�p�e�s��>[.<���i�s��>]|new|next
�R���p��: terminate <�d���s��> 

LONG
 );
	setup();
}