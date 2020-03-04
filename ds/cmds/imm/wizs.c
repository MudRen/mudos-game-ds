#include <mudlib.h>
#include <ansi.h>

int main(object me,string arg)
{
    object *all_wizards ;
    int val, invisible ;
    string inv,lvname,doing;

    all_wizards = filter_array( users(), (: wizardp($1) :) );
	all_wizards = sort_array(all_wizards, "sort_wizards", this_object()) ;
	write(HIC+"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n") ;
	write(HIM+"                  �ثe�@�� "+ sizeof(all_wizards) + " �ӧŮv�b�u�W\n") ;
	write(HIC+"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n") ;

	foreach( object wiz in all_wizards )
	{
	    if(me->visible(wiz))
	    {
                write(sprintf("%12s",RANK_D->query_rank(wiz)));
	    lvname = wiz->short(1);
	    write(sprintf(" %-37s",lvname));
	    val = query_idle( wiz );
	    doing = "";
	    if (val >= 60)
		doing = "[�b�F"+ val/60 + "����]";
	    if (val >= 3600)
		doing = "[�b�F"+ val/3600 + "�p��]";
	    write(HIY+sprintf("%-12s",doing));
	    doing="";
	    if(wiz->in_edit()) doing="<�V�O�s�褤>";
	    write(HIR+sprintf("%-12s",doing));
	    invisible = wiz->query_temp("invis");
	    inv = "";
	    if (invisible >= 2) inv = "[���ΧŮv]";
	    write(HIR+sprintf("%-10s",inv)+"\n");
	} else write(HIC+"  << �Y�Ӱ��ŧŮv >>\n"+NOR);
    }
      write(HIC+"--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"+NOR);
      return 1;
  }

    int sort_wizards(object ob1, object ob2)
    {
	if( ((int)wiz_level(ob1) - (int)wiz_level(ob2) ) != 0 )
	    return ( (int)wiz_level(ob2) - (int)wiz_level(ob1) );
	return strcmp((string)ob2->query("id"), (string)ob1->query("id"));
    }
