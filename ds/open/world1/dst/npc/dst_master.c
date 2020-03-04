// �� NPC ����Ϊ�..
#define MSG(x)          write(x+"\n");

inherit F_DBASE;

int shout_dst(string arg);
string upper_path(string file, int i);

void create()
{
        set("channel_id", "�j�N���t�w����");
        set("id", "Past_west_DST");
}

int shout_dst(string arg)
{
        object room;
        string path, *dstz;

        path = upper_path(base_name(this_object()), 1);
        if( path == "" )
		return notify_fail(" DST_MASTER �W�h�ؿ��j�M���ѡA�гq���Ův�C\n");
        else dstz = get_dir(path);

// debug
        MSG("DEBUG: path = " + path);
//

        for(int i=0;i<sizeof(dstz);i++)
        {
		MSG("Running i="+i+"; "+ dstz[i]);
                if( file_size(path+dstz[i]) == -2 ) continue;
                if( room = load_object(path + dstz[i]) )
                {
                        if( room->is_room() )
                        {
                                tell_room(room, arg, ({ }));
// debug
                                MSG("DEBUG: "+base_name(room)+ " has been sent.");
//
                        }
                }
                else return notify_fail("Error: "+ path+dstz[i]+ " loading failed. �гq���Ův�C\n");
        }
        return 1;
}

// upper_path �W�@�h�ؿ�

string upper_path(string file, int i)
{
        string *dir;

        dir = explode(file, "/");
        dir = dir[0..<2]; // dir[0..<2] == dir[0..sizeof(dir)-2]

	if( i++ >= sizeof(dir) )
                return "";
        dir = dir[0..sizeof(dir)-i];
	return "/"+implode(dir, "/")+"/";  // �� get_dir �n�� /
}
