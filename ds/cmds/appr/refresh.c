// pwd.c
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
  {
   object ob;
        
	if( !arg ) {
	   me->delete("wound");
		message_vision(HIY"$N喃喃唸道: 木之精靈啊! 我以卡耐爾之名召喚你.. 用芳香的花露, 滋潤大地的唇..\n"NOR
		+"$N身上的傷口漸漸復原了..\n",me);
	   return 1;    }
	  else {
	    ob = present(arg,environment(me));
	    if (!ob) ob = find_living(arg);
	    if (!ob) return notify_fail("沒有這玩家或是生物。\n");
	    else ob->delete("wound");
 		message_vision(HIW"$N的周圍出現了幾道淡綠色的光環, 身上的傷口漸漸癒合了。\n"NOR,ob);
	        return 1;    
	     }     
}

int help(object me)
{
write(@HELP
指令格式 : refresh
 這可以讓你的傷口復原.    用法refresh <對象>
 
HELP
    );
    return 1;
}
