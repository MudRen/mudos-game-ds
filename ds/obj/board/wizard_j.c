// wizard_j.c

inherit "/std/jboard";

void create()
{
	set_name("巫師工作進度報告", ({ "job board", "board" }) );
	set("location", "/d/wiz/jobroom");
	set("board_id", "wizard_j");
	set("long",@LONG

這是一個特殊的留言板供巫師報告自己的工作進度。
使用方法: 

新增計劃: project   <標題>
報告進度: report    <計畫編號> <進度報告標題>
閱讀計劃: read      <計畫編號>[.<報告編號>]|new|next
刪除計劃: terminate <留言編號> 

LONG
 );
	setup();
}
