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
	
	if( !arg ) return notify_fail("�A�n�ꤰ��S\n");
	if( sscanf(arg, "%s with %s", dest, key)==2 )
	{
		if(!keyob=present(key, me)) return notify_fail("�A���W�èS "+key+"�C\n");
		if(obj=present(dest, env))
		{
			if(obj->is_box())
			{
				switch(obj->query_cover_status())
				{
					case COVER_NONE : return notify_fail(obj->name()+"�èS���a��i�H���A�W��C\n");
					case COVER_OPENED : return notify_fail("�n����"+obj->name()+"��"+obj->query("cover_name")+"���W�~��W��C\n");
					case COVER_SMASHED : return notify_fail(obj->name()+"��"+obj->query("cover_name")+"�w�g�a�F�C\n");
				}
				switch(obj->query_lock_status())
				{
					case LOCK_NONE : return notify_fail(obj->name()+"�èS���a��i�H���A�W��C\n");
					case LOCK_CLOSED : return notify_fail(obj->name()+"��"+obj->query("cover_name")+"�w�g��W�F�C\n");
					case COVER_SMASHED : return notify_fail(obj->name()+"����w�g�a�F�C\n");
				}
				
				if(obj->close_lock(keyob)==1)
				{
					message_vision("�y..��!!�z$N��"+keyob->name()+"�N$n��W�F�C\n",me,obj);
					return 1;
				} else return notify_fail("�y..��!!�z�A���G��"+obj->name()+"���굹���a�F�C\n");
			} else return notify_fail("���ӪF�褣��W��C\n");
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
		if( !dir ) return notify_fail("�o�Ӥ�V�S�����C\n");
		key=env->query_door(dir,"key");
		if(!key ) return notify_fail("�o�Ӫ��ä��i�H�W��!\n");
		if( doors[dir]["status"] == DOOR_SMASHED )
	        	return notify_fail("�o��" + doors[dir]["name"] + "�w�g�a�F�C\n");
		if( doors[dir]["status"] == DOOR_LOCKED  )
			return notify_fail( doors[dir]["name"] + "�w�g�O����F�C\n");
		if( doors[dir]["status"] == DOOR_OPENED  )
			return notify_fail( "�n����" + doors[dir]["name"] + "���_�Ӥ~����C\n");
		if(!keyob)
		{
			if(env->query("free_lock/"+dir))
			{
        	 			if(env->lock_door(dir))
        	 			{
	       	   		 		message_vision("�y..��!!�z"+"$N�N" + doors[dir]["name"] + "��W�C\n", me);
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
	       	   		 		message_vision("�y..��!!�z"+"$N��"+inv[i]->query("name")+"�N" + doors[dir]["name"] + "��W�C\n", me);
	       	   				return 1;
		 			}
				}
			}
			return notify_fail("�A�S�X�A���_�ͱN���W��C\n");
		} else
		{
			mykey=keyob->query("door");
			if(mykey==key)
			{
      	 			if(env->lock_door(dir))
       	 			{
      	   		 		message_vision("�y..��!!�z"+"$N��"+inv[i]->query("name")+"�N" + doors[dir]["name"] + "��W�C\n", me);
       	   				return 1;
	 			} else return notify_fail("�A�L�k���\\���N"+doors[dir]["name"]+"��W�C\n");
			}
			else return notify_fail("�A��"+keyob->name()+"�P���W����ä��ŦX�C\n");
		}
	} else return notify_fail("�o�̨S�����C\n");
	return 0;
}

int help(object me)
{
 write(@HELP

  ���O�榡 : lock <door||��V> with <�_��>
  ���O�榡 : lock <���~> with <�_��>

  �o�ӫ��O�i�H���A���_����W���άO�c�l.
 
HELP
    );
    return 1;
}
