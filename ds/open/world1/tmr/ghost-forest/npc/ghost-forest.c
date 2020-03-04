#include <ansi.h>

int ghost_heal(object ob);
int ghost_kill(object ob);

int ghost_heal(object ob) 
{
	if( ob->is_busy() )	return 1;
         if( ob->query("hp") > ob->query("max_hp")/2 ) return 1;
	message_vision( CYN "\n$N"+ CYN "嘶吼一聲，身上冒出陣陣屍氣...\n" NOR,ob);
	ob->receive_heal("hp",ob->query("hp")/10 );
	return 1;
}

int ghost_kill(object ob)
{
	if(ob->is_busy() ) return 1;
	switch(random(3) ) {
	case 0:
                message_vision(HIM "\n$N眼中殺機一現，挺著身子又上前一步..\n" NOR,ob);
		ob->attack();
	break;
	case 1:
		message_vision(RED "$N舔了舔沾在白銀戰甲上的汨汨鮮血....\n" NOR,ob);
		ob->receive_heal("hp",ob->query("hp")/10 );
	break;
	case 2:
		message_vision(HIY "\n$N頭上的金黃羽盔發出一陣耀眼的光芒，你幾乎快睜不開眼睛了......\n" NOR,ob);
		ob->query_enemy()->start_busy(1);
	break;
	}
	return 1;
}
