// close.c

#include <room.h>
#include <box.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping doors;
          string *dirs, dir;
	int i,code;
	object env,obj;
	
	if( !arg ) return notify_fail("�A�n��������S\n");
	env=environment(me);
	if(!env) return 0;
	
	if(obj=present(arg, env))
	{
		if(obj->is_box())
		{
			code=obj->close_cover();
			switch(code)
			{
				case 1:	
					message_vision("$N��$n��"+obj->query("cover_name")+"���W�F�C\n",me,obj);
					return 1;
					break;
				case COVER_NONE: return notify_fail(obj->name()+"�èS���\\�l�C\n");
				case COVER_CLOSED: return notify_fail(obj->name()+"��"+obj->query("cover_name")+"�w�g�O���۪��C\n");
				case COVER_SMASHED: return notify_fail(obj->name()+"��"+obj->query("cover_name")+"�w�g�a�F�C\n");
				default:
					return notify_fail("�X�F�I���D�F!�Ч�Ův�����ѨM!!\n ���~�N��: open_lock="+code+"\n");
			}
        } else return notify_fail("�A�n��"+obj->name()+"���W!?\n");
	}
	
	doors = env->query_doors();
	if( mapp(doors) )
	{
		dirs = keys(doors);
		if( member_array(arg, dirs)!=-1 ) dir = arg;
		else for(i=0; i<sizeof(dirs); i++)
			if( arg==doors[dirs[i]]["name"] || member_array(arg, doors[dirs[i]]["id"])!=-1 ) {
				dir = dirs[i];
				break;
			}
		if( !dir ) return notify_fail("�o�Ӥ�V�S�����C\n");
		if( doors[dir]["status"] == DOOR_SMASHED )
	        	return notify_fail("�o��" + doors[dir]["name"] + "�w�g�a�F�C\n");

		if( !(doors[dir]["status"] == DOOR_OPENED) )
			return notify_fail( doors[dir]["name"] + "�w�g�O���۪��F�C\n");

		if( env->close_door(dir) ) {
			message_vision("$N�N" + doors[dir]["name"] + "���W�C\n", me);
			return 1;
		} 
	} else return notify_fail("�o�̨S�����C\n");

	return 0;
}

int help(object me)
{
        write(@HELP
���O�榡 : close <door> �� <��V>
 
�o�ӫ��O�i�H���A���W��.
 
HELP
    );
    return 1;
}
