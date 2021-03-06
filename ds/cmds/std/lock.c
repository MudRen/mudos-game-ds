// close.c

#include <room.h>
#include <box.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping doors;
	string *dirs, dir, key, mykey, dest;
	int i;
	object *inv, env, keyob,obj;
	
	env = environment(me);
	if(!env) return 0;
	
	if( !arg ) return notify_fail("你要鎖什麼﹖\n");
	if( sscanf(arg, "%s with %s", dest, key)==2 )
	{
		if(!keyob=present(key, me)) return notify_fail("你身上並沒 "+key+"。\n");
		if(obj=present(dest, env))
		{
			if(obj->is_box())
			{
				switch(obj->query_cover_status())
				{
					case COVER_NONE : return notify_fail(obj->name()+"並沒有地方可以讓你上鎖。\n");
					case COVER_OPENED : return notify_fail("要先把"+obj->name()+"的"+obj->query("cover_name")+"關上才能上鎖。\n");
					case COVER_SMASHED : return notify_fail(obj->name()+"的"+obj->query("cover_name")+"已經壞了。\n");
				}
				switch(obj->query_lock_status())
				{
					case LOCK_NONE : return notify_fail(obj->name()+"並沒有地方可以讓你上鎖。\n");
					case LOCK_CLOSED : return notify_fail(obj->name()+"的"+obj->query("cover_name")+"已經鎖上了。\n");
					case COVER_SMASHED : return notify_fail(obj->name()+"的鎖已經壞了。\n");
				}
				
				if(obj->close_lock(keyob)==1)
				{
					message_vision("『..喀!!』$N用"+keyob->name()+"將$n鎖上了。\n",me,obj);
					return 1;
				} else return notify_fail("『..啪!!』你似乎把"+obj->name()+"的鎖給弄壞了。\n");
			} else return notify_fail("那個東西不能上鎖。\n");
		}
	}
	doors = env->query_doors();
	if( mapp(doors) )
	{
		dirs = keys(doors);
		if( member_array(arg, dirs)!=-1 ) dir = arg;
		else for(i=0; i<sizeof(dirs); i++)
			if( arg==doors[dirs[i]]["name"] || member_array(arg, doors[dirs[i]]["id"])!=-1 )
			{
				dir = dirs[i];
				break;
			}
		if( !dir ) return notify_fail("這個方向沒有門。\n");
		key=env->query_door(dir,"key");
		if(!key ) return notify_fail("這個門並不可以上鎖!\n");
		if( doors[dir]["status"] == DOOR_SMASHED )
	        	return notify_fail("這個" + doors[dir]["name"] + "已經壞了。\n");
		if( doors[dir]["status"] == DOOR_LOCKED  )
			return notify_fail( doors[dir]["name"] + "已經是鎖住的了。\n");
		if( doors[dir]["status"] == DOOR_OPENED  )
			return notify_fail( "要先把" + doors[dir]["name"] + "關起來才能鎖。\n");
		if(!keyob)
		{
			if(env->query("free_lock/"+dir))
			{
        	 			if(env->lock_door(dir))
        	 			{
	       	   		 		message_vision("『..喀!!』"+"$N將" + doors[dir]["name"] + "鎖上。\n", me);
	       	   				return 1;
		 			}	
			}
			
			inv = all_inventory(me);
			for(i=0;i<sizeof(inv);i++)
			{
				mykey=inv[i]->query("door");
        			if(mykey==key)
        			{
        	 			if(env->lock_door(dir))
        	 			{
	       	   		 		message_vision("『..喀!!』"+"$N用"+inv[i]->query("name")+"將" + doors[dir]["name"] + "鎖上。\n", me);
	       	   				return 1;
		 			}
				}
			}
			return notify_fail("你沒合適的鑰匙將門上鎖。\n");
		} else
		{
			mykey=keyob->query("door");
			if(mykey==key)
			{
      	 			if(env->lock_door(dir))
       	 			{
      	   		 		message_vision("『..喀!!』"+"$N用"+inv[i]->query("name")+"將" + doors[dir]["name"] + "鎖上。\n", me);
       	   				return 1;
	 			} else return notify_fail("你無法成功\的將"+doors[dir]["name"]+"鎖上。\n");
			}
			else return notify_fail("你的"+keyob->name()+"與門上的鎖並不符合。\n");
		}
	} else return notify_fail("這裡沒有門。\n");
	return 0;
}

int help(object me)
{
 write(@HELP

  指令格式 : lock <door||方向> with <鑰匙>
  指令格式 : lock <物品> with <鑰匙>

  這個指令可以讓你用鑰匙鎖上門或是箱子.
 
HELP
    );
    return 1;
}
