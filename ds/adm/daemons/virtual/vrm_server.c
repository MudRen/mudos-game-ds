/************************************************
 * vrm_server.c                                 *
 * �������H���g�c�гy�� (Virtual Random Maze)   *
 *                                              *
 * by Find.                                     *
 *              �������� �ѤU MUD.              *
 ************************************************/

/******************************************************
 * �g�c�O�@�Ӵ������g�`�n�Ψ쪺�F��A�H�e���g�c���ݭn *
 * �Ův�@�өж��@�өж��a��uø��A�O�ɶO�O�A�ӥB�@�� *
 * �Q���a��X���T���u���A�g�c�槽�Q�n�|�A�g�c�N���٨� *
 * ���g�c�F�A�ҥH�Ův�̳����ɸ��ħ�g�c�]�p���ɶq�_��,*
 * ���A�_�����g�c���ߤ]�|�Q��쥿�T�����u�A�ӥB�L�_�_ *
 * ���������g�c�]�Ϫ��a�Pı�L�_�c���A���C�ֽ�C�]���� *
 * �ͦ��Q�k�C                                         *
 * �H���g�c�����ͺ�k�ɶq²��A�g�c���x�s�ɶq�`�ٰO�� *
 * ��A�g�c�ж����ε�������A�B�z�F���A�g�c�ж��u���b *
 * ���a����ɤ~�|�˶i���s�A�ӥB�g�c�ж��]�H���q��ROOM *
 * �@�˷�@�q�ɶ��S���Q�ѦҨ�i�H�P���`�ٰO����A��� *
 * �Ӱg�c�@�q�ɶ��S���Q�ѦҨ�i�H�Q�����R���A�U���A�� *
 * �n���ɭԷ|���s�إߡA�S�|���ͤ@�ӷs���g�c�C�ϰ�Ův *
 * �g�@�H���g�c�u�ݳW�w�@�ǹw�]���ѼƦp�g�c��������B *
 * �ж��y�z�B�X�J�f�y�z�A�L�Q�ӤD�ܤL�d�өж��B���u�� *
 * �ɤ��P���H���g�c�N�إߦn�F�A�j�j�����F�ϰ�g�@�Ĳv *
 * �M�������i���ʡC                                   *
 * ������ثe�A�X�_�H�����g�c�A�Y�G�g�c���ж����y�z�� *
 * ���ۦP�A��p�@����L�B�@���X�a���A�p�n������Ч@�� *
 * �㪺�H���ϰ�Y���@�w�����`�B�@�w�槽���ϰ�A�h�ݭn *
 * �ھڦۤv�����p�W�w�X�g�c���ж��y�z���@�ǳW�h�A�Ϭ� *
 * �F�ж����y�z�ܤƦX�z�A�ж�������P�y�z��աC�p�G�@ *
 * �N�Ův�i�H�u��@�g�c�����s�������A�ӥΤL�Ӱg�c�զX *
 * ���@�ӧ����H�����ϰ�A���A���H�Z���Ův�i���Q�h�F�C *
 * �ثe�������ϥΪ��g�c�@�묰�����10��40�A�쩳�వ�h *
 * �j���g�c�ڤ]�����D�A�U���惡���@�ӻ����A�n�ھڦۤv *
 * ���A�Ⱦ��ʯ�����A���L�ڷQ�̴��q��������@�@�ӭ��n *
 * ��100x100���g�c���Ӥ]�O�@�󻴪Q���Ʊ��C            *
 * �Ѥ_���� virtual object�A�o�A��@�I�w�����D�A�ݭn��*
 * �ڦۤv���t�ΦҶq�վ�C                             *
 ******************************************************/

#pragma optimize

#define N		8
#define S		4
#define W		2
#define E		1
#define ALL		15

/****************************************************
 * �g�c��������̤j�ȥثe�ȩw�� 100�A�Ѥ_�H���g�c��
 * �гy�M�ާ@����ӶO�귽����� 100 ���g�c'���n'�N�O
 * 100x100 ���_ 10000 �өж����@�Ӱg�c�A�@�뮣�ȬO��
 * ����C�@�몺��ɰg�c�]��ɰg�c�O���b�����B��L�{
 * ���H�ɳQ destruct �H�ۻݭn�S�|�H�ɳQ�Ыت��g�c�^��
 * ������H 10 �� 50 �������y�C�p�ݳгy�����g�c�p���L
 * �U�D�ܤQ�L�U�өж����g�c�A���N�Ыؤu�@��m�_������
 * �ʮɰ��A�����Ұʪ��@�q�ɶ��]��p20��^�T��a�n�J�C
 * �����q�L�w�����s�Ұʨӧ�s���g�c�C
 * �����ַ|�Ψ�o�\�j���g�c�C�C�C�C�C�C
 ****************************************************/
#define MAX_LONG	100

// �u�n��P��L�ж��۳s���ж��N�֩w���@�ӤJ�f.
// �ӥi�઺�X�f���T��.
// define �o���W�w�ж��̦h�u�঳��ӥX�f.
// �]�N�O��_���T�ӥX�f���ж��|�H�������@��.
// ���|�Ϫ��a�Ѥ_�ݨ�|�Ӥ�V�����X�f�ܷ�
// ���C�����ֽ�C
#define TWO_VALID_LEAVES

inherit F_CLEAN_UP;

class coordinate{ int x; int y; }
class coordinate *newpath = ({}),/*�ݳB�z���C*/
	enter,/* �J�f���� */
	leave;/* �X�f���� */

private string *valid_dirs = ({ "south","north","west","east" });
private mapping reverse_dir = ([
"north" : "south",
"south" : "north",
"west"  : "east",
"east"  : "west",
]);

// ���g�c�X�f�}�C.
private mixed *all;

/***************** �g�c���@�ǹw�]�S�ʡG*****************/
private int l;				// �g�c�������
private string *inherit_rooms = ({});	// �g�c���\�~�Ӫ��ɮצW��
private string entry_dir;		// �g�c�J�f��V
private string link_entry_dir;		// �g�c�J�f�P�ϰ쪺�s����V
private string link_entry_room;		// �g�c�J�f�ҳs���ϰ��ɮת����W
private string link_exit_dir;		// �g�c�X�f�P�ϰ쪺�s����V
private string link_exit_room;		// �g�c�X�f�ҳs���ϰ��ɮת����W
private string entry_short;		// �g�c�J�f���u�y�z
private string entry_desc;		// �g�c�J�f�����y�z
private string exit_short;		// �g�c�X�f���u�y�z
private string exit_desc;		// �g�c�X�f�����y�z
private string *maze_room_desc	= ({});	// �g�c�ж������y�z
private string maze_room_short;		// �g�c�ж����u�y�z
private int is_outdoors = 0;		// �g�c�ж��O�_����~
private string *maze_npcs = ({});	// �g�c�����Ǫ�
/******************* ---- END ---- *********************/

// �إ߼аO.
private int maze_built = 0;

// ���m�����ܶq.
private void refresh_vars();

// �إ߰g�c
private void create_maze();

// ����H���X�f.
private int random_out(int x,int y,int n);

// �B�z�s��.
private void link_to_north(int x,int y);
private void link_to_south(int x,int y);
private void link_to_west(int x,int y);
private void link_to_east(int x,int y);

// ø��w�ئ��g�c���a��.
private void paint_vrm_map();

private string mroom_fname(int x,int y)
{ return sprintf("%s/%d/%d",base_name(this_object()),x,y);}


private void refresh_vars() // ���m�����ܶq.
{
	newpath = ({});
	all = 0;
}

// ��@�ǥ��]�Ѽƪ��X�k���ˬd
private int check_vars()
{
	int i,n;

	if( (l < 5) || l > MAX_LONG )
		return 0;

	inherit_rooms -=({0});
	if( !n = sizeof(inherit_rooms) )
		return 0;

	for(i=0;i<n;i++)
		if(!stringp(inherit_rooms[i]) || (inherit_rooms[i] == ""))
			return 0;

	if(!stringp(entry_dir) || (member_array(entry_dir,valid_dirs) == -1) )
		return 0;
/*
	if(!stringp(link_entry_dir) || (member_array(link_entry_dir,valid_dirs) == -1) )
		return 0;

	if(!stringp(link_exit_dir) || (member_array(link_exit_dir,valid_dirs) == -1) )
		return 0;
*/
	if(!stringp(link_entry_room) || (link_entry_room == ""))
		return 0;

	if(!stringp(link_exit_room) || (link_exit_room == ""))
		return 0;

	if(!stringp(entry_short) || (entry_short == ""))
		return 0;

	if(!stringp(exit_short) || (exit_short == ""))
		return 0;

	if(!stringp(entry_desc) || (entry_desc == ""))
		return 0;

	if(!stringp(exit_desc) || (exit_desc == ""))
		return 0;

	maze_room_desc -=({0});
	if( !n = sizeof(maze_room_desc) )
		return 0;

	for(i=0;i<n;i++)
		if(!stringp(maze_room_desc[i]) || (maze_room_desc[i] == ""))
			return 0;

	if(!stringp(maze_room_short) || (maze_room_short == ""))
		return 0;

	return 1;
}

private int random_out(int x,int y,int n) // ����H���X�f���.
{
	int *outs = ({}), retn = 0;
	class coordinate temp;

	// The west room is (x-1,y)
	if( n&W
	&& ((x-1) >= 0)
	&& !all[x-1][y] )
	{
		temp = new(class coordinate);
		temp->x = x-1;
		temp->y = y;

		// �譱���ж����b�ݳB�z�C�� newpath ��.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ W });
	}

	// The east room is (x+1,y)
	if( n&E
	&& ((x+1) < l)
	&& !all[x+1][y] )
	{
		temp = new(class coordinate);
		temp->x = x+1;
		temp->y = y;

		// �F�����ж����b�ݳB�z�C�� newpath ��.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ E });
	}

	// The south room is (x,y-1)
	if( n&S
	&& ((y-1) >= 0)
	&& !all[x][y-1] )
	{
		temp = new(class coordinate);
		temp->x = x;
		temp->y = y-1;

		// �n�����ж����b�ݳB�z�C�� newpath ��.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ S });
	}

	// The north room is (x,y+1)
	if( n&N
	&& ((y+1) < l)
	&& !all[x][y+1] )
	{
		temp = new(class coordinate);
		temp->x = x;
		temp->y = y+1;

		// �_�����ж����b�ݳB�z�C�� newpath ��.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ N });
	}

#ifdef TWO_VALID_LEAVES
	// �p�G���T�ӥX�f,�H�������@��.
	if(sizeof(outs) >= 3)
		outs -= ({ outs[random(sizeof(outs))] });
#endif

	for(int i=0;i<sizeof(outs);i++)
		retn |= outs[i];

	return retn;
}

private void create_maze()
{
	int i;
	class coordinate *valid_leaves=({}),temp;

	refresh_vars(); // ���m�����ܶq.
	if( !check_vars() )   // ��@�ǹw�]�ܶq�i���ˬd�C
		return;

	// 1.�T�w�g�c�����.
	all = allocate(l);
	for(i=0;i<l;i++)
		all[i] = allocate(l);	// �إ߼Ʋ�.

	enter = new(class coordinate);

	switch (entry_dir)
	{
		case "south":
			// enter �J�f����.
			enter->x = to_int(l/2); // �����g�c������šC
			enter->y = 0;
			all[enter->x][enter->y] |= S;
			break;
		case "north":
			enter->x = to_int(l/2);
			enter->y = l-1;
			all[enter->x][enter->y] |= N;
			break;
		case "west":
			enter->y = to_int(l/2);
			enter->x = 0;
			all[enter->x][enter->y] |= W;
			break;
		case "east":
			enter->y = to_int(l/2);
			enter->x = l-1;
			all[enter->x][enter->y] |= E;
			break;
	}

	// �s�J�ݳB�z���C.
	newpath += ({ enter });

	// �i�J�D�`��.
	do
	{
		int x,y,out,numb;

		// �i��@�Ǻʴ��P��l��.
		if( !(numb=sizeof(newpath)) )
			continue;
		numb = random(numb);
		reset_eval_cost();
		x = newpath[numb]->x;
		y = newpath[numb]->y;

		// �p�G���T�ӥi�઺�X�f�H�������@�ӥX�f:
		out = ALL^(all[x][y]);
		out = random_out(x,y,out);

		if(!out) // �S���i�઺�X�f�F.
		{
			newpath -= ({ newpath[numb] });
			continue;
		}

		// �B�z�s��.
		if(out&W) link_to_west(x,y);
		if(out&E) link_to_east(x,y);
		if(out&N) link_to_north(x,y);
		if(out&S) link_to_south(x,y);

		// ��e�ж��B�z����.
		newpath -= ({ newpath[numb] });
	}
	while (sizeof(newpath));

	switch (entry_dir)
	{
		case "west":
			for(i=0;i<l;i++)
				if(all[l-1][i])
				{
					temp = new(class coordinate);
					temp->x = l-1;
					temp->y = i;
					valid_leaves += ({temp});
				}
			break;
		case "east":
			for(i=0;i<l;i++)
				if(all[0][i])
				{
					temp = new(class coordinate);
					temp->x = 0;
					temp->y = i;
					valid_leaves += ({temp});
				}
			break;
		case "south":
			for(i=0;i<l;i++)
				if(all[i][l-1])
				{
					temp = new(class coordinate);
					temp->x = i;
					temp->y = l-1;
					valid_leaves += ({temp});
				}
			break;
		case "north":
			for(i=0;i<l;i++)
				if(all[i][0])
				{
					temp = new(class coordinate);
					temp->x = i;
					temp->y = 0;
					valid_leaves += ({temp});
				}
			break;
	}

	if( !(i=sizeof(valid_leaves)) ) // �S���X�f �����s�إ�
	{
		call_other(this_object(),"create_maze");
		return;
	}

	if(i == 1)
		leave = valid_leaves[0];
	else
		leave = valid_leaves[random(i)]; // �H����@��.

	switch (entry_dir)
	{
		case "south":
			all[leave->x][leave->y] |= N;
			break;
		case "north":
			all[leave->x][leave->y] |= S;
			break;
		case "west":
			all[leave->x][leave->y] |= E;
			break;
		case "east":
			all[leave->x][leave->y] |= W;
			break;
	}

	// �g�c�Ыا����C
	maze_built = 1;

	// ø������g�c�a�ϡC
	// �a�Ϥ�󬰦P�ؿ��U�P�W��'.map' ���A
	// ø��a�Ϥ]�\�i�Q�_�ϰ�Ův���u�@�C
	// �p�ݭn�i�}�񪫥��_���ؿ���'�g'�C
	//paint_vrm_map();
}

private void link_to_west(int x,int y)	// The west room is (x-1,y)
{
	class coordinate temp;
	// can't link. ��e�ж��w�g�O�̦譱���ж��F.
	if( (x-1) < 0 )
		return;

	temp = new(class coordinate);
	temp->x = x-1;
	temp->y = y;

	// �譱���ж��w�g�_ path ��,�Ϊ� �w�b�ݳB�z�C�� newpath ��.
	if(all[temp->x][temp->y] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y] |= W;
	all[temp->x][temp->y] |= E;
	newpath += ({temp});
}

private void link_to_east(int x,int y)	// The east room is (x+1,y)
{
	class coordinate temp;
	// can't link. ��e�ж��w�g�O�̪F�����ж��F.
	if( (x+1) >= l )
		return;

	temp = new(class coordinate);
	temp->x = x+1;
	temp->y = y;

	// �F�����ж��w�g�_ path ��,�Ϊ� �w�b�ݳB�z�C�� newpath ��.
	if(all[temp->x][temp->y] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y] |= E;
	all[temp->x][temp->y] |= W;
	newpath += ({temp});
}

private void link_to_south(int x,int y)	// The south room is (x,y-1)
{
	class coordinate temp;
	// can't link. ��e�ж��w�g�O�̫n�ݪ��ж��F.
	if( (y-1) <0 )
		return;

	temp = new(class coordinate);
	temp->x = x;
	temp->y = y-1;

	// �n�ݪ��ж��w�g�_ path ��,�Ϊ� �w�b�ݳB�z�C�� newpath ��.
	if(all[temp->x][temp->y] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y] |= S;
	all[temp->x][temp->y] |= N;
	newpath += ({temp});
}

private void link_to_north(int x,int y)	// The north room is (x,y+1)
{
	class coordinate temp;
	// can't link. ��e�ж��w�g�O�̥_�ݪ��ж��F.
	if( (y+1) >= l )
		return;

	temp = new(class coordinate);
	temp->x = x;
	temp->y = y+1;

	// �_�ݪ��ж��w�g�_ path ��,�Ϊ� �w�b�ݳB�z�C�� newpath ��.
	if(all[temp->x][temp->y] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y] |= N;
	all[temp->x][temp->y] |= S;
	newpath += ({temp});
}

// ø��w�ئ��g�c���a��.
private void paint_vrm_map()
{
	string hor = "�w" ,ver = "�x  ",room = "��",sroom = "��";
	int x,y;
	string output = "",map_file;

	for(y=(l-1);y>=0;y--)
	{
		reset_eval_cost();

		output += sprintf("y=%-3d: ",y);
		for(x=0;x<l;x++)
		{
			output += sprintf("%s",
				(( (x==enter->x) && (y==enter->y))
				|| ( (x==leave->x) && (y==leave->y) ))?
				sroom:room);

			if( (all[x][y])&E ) // have east
				output += hor;
			else
				output += "  ";
		}

		output += "\n";
		output += "       ";
		for(x=0;x<l;x++)
		{
			if( (all[x][y])&S ) // have south
				output += ver;
			else
			output += "    ";
		}
		output += "\n";
	}

	map_file = sprintf( "%s.map",base_name(this_object()) );
	write_file(map_file,output,1);
}

nomask int clean_up()
{
	string fname;
	int x,y;
	object *maze_objs = ({}),link_room;

	if(!maze_built)
	{
		destruct(this_object());
		return 0;
	}

	fname = base_name(this_object());

	if( objectp(link_room = find_object(sprintf("%s/entry",fname))) )
	{
		link_room->clean_up();
		if( objectp(link_room) )
			return 1;
	}

	if( objectp(link_room = find_object(sprintf("%s/exit",fname))) )
	{
		link_room->clean_up();
		if( objectp(link_room) )
			return 1;
	}

	for(x=0;x<l;x++)
		for(y=0;y<l;y++)
			if(objectp(find_object(sprintf("%s/%d/%d",fname,x,y))))
				maze_objs += ({find_object(sprintf("%s/%d/%d",fname,x,y))});

	maze_objs->clean_up();
	maze_objs -= ({0});

	if(sizeof(maze_objs))
		return 1;
	else
	{
		destruct(this_object());
		return 0;
	}
}

// �Ův�i�H update �ϰ�g�c�D����j���s�g�c�A
// �����ɰg�c�������a�N�n�h VOID �F�C
void remove(string euid)
{
	string fname = base_name(this_object());
	object m_room;
	int x,y;

	for(x=0;x<l;x++)
		for(y=0;y<l;y++)
			if(objectp(m_room = find_object(sprintf("%s/%d/%d",fname,x,y))))
				destruct(m_room);
	if(find_object(sprintf("%s/entry",fname)))
		destruct(sprintf("%s/entry",fname));
	if(find_object(sprintf("%s/exit",fname)))
		destruct(sprintf("%s/exit",fname));
}

/**** �H�U�O�w�]�g�c�Ѽƪ����f��� ****/
// �g�c�������
void set_maze_long(int mlong)
{
	if(!intp(mlong))
		return;

	// �̤p�� 5�A�A�p�F�S���\�N�q�C
	if( (mlong < 5) || mlong > MAX_LONG )
		return;

	l = mlong;
}

// �g�c�ж����~�Ӫ������ɮצW�١C
void set_inherit_room( mixed rooms )
{
	if(stringp(rooms))
	{
		// ���ɮ׬O�_�s�b
		if(file_size(sprintf("%s.c",rooms)) > 0)
			inherit_rooms = ({ rooms });
		return;
	}

	else if(arrayp(rooms))
	{
		foreach(string f in rooms)
		{
			if(!stringp(f) || f == "")
				return;
			if(file_size(sprintf("%s.c",f)) <= 0)
				return;
		}
		inherit_rooms = rooms;
		return;
	}

	return;
}

// �J�f��V(�X�f�b�ﭱ)
void set_entry_dir(string dir)
{
	if(!stringp(dir))
		return;

	// �J�f��V���X�k���ˬd.
	if(member_array(dir,valid_dirs) == -1)
		return;

	entry_dir = dir;
}

//�J�f�P�ϰ쪺�s����V
void set_link_entry_dir(string dir)
{
	if(!stringp(dir) || dir == "")
		return;

	link_entry_dir = dir;
}

// �g�c�J�f�ҳs���ϰ��ɮת����W
void set_link_entry_room(string lroom)
{
	if(!stringp(lroom) || lroom == "")
		return;

	if(file_size(sprintf("%s.c",lroom)) <= 0)
		return;

	link_entry_room = lroom;
}

//�X�f�P�ϰ쪺�s����V
void set_link_exit_dir(string dir)
{
	if(!stringp(dir) || dir == "")
		return;

	link_exit_dir = dir;
}

// �g�c�X�f�ҳs���ϰ��ɮת����W
void set_link_exit_room(string lroom)
{
	if(!stringp(lroom) || lroom == "")
		return;

	if(file_size(sprintf("%s.c",lroom)) <= 0)
		return;

	link_exit_room = lroom;
}

// �g�c�J�f���u�y�z
void set_entry_short(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	entry_short = desc;
}

// �g�c�J�f�����y�z
void set_entry_desc(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	entry_desc = desc;
}

// �g�c�X�f���u�y�z
void set_exit_short(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	exit_short = desc;
}

// �g�c�X�f�����y�z
void set_exit_desc(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	exit_desc = desc;
}

//�g�c�ж����u�y�z
void set_maze_room_short(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	maze_room_short = desc;
}

//�g�c�ж����y�z�A�p�G���h���y�z�A��y�C�ө�
//�����ɭԷ|�q���H����ܤ@�ӡC
void set_maze_room_desc(mixed desces)
{
	if(stringp(desces))
	{
		maze_room_desc = ({ desces });
		return;
	}

	if(arrayp(desces))
	{
		foreach(string desc in desces)
			if(!stringp(desc))
				return;
		maze_room_desc = desces;
		return;
	}
}

// �g�c�ж��O�_����~�ж�
void set_outdoors(int outd)
{
	if(!intp(outd))
		return;

	if(outd)
		is_outdoors = 1;
}

// �g�c�����Ǫ�
void set_maze_npcs(mixed npc)
{
	if(stringp(npc))
	{
		// ���ɮ׬O�_�s�b
		if(file_size(sprintf("%s.c",npc)) > 0)
			maze_npcs = ({ npc });
		return;
	}

	else if(arrayp(npc))
	{
		foreach(string f in npc)
		{
			if(!stringp(f) || f == "")
				return;
			if(file_size(sprintf("%s.c",f)) <= 0)
				return;
		}
		maze_npcs = npc;
		return;
	}

	return;

}

/**** �H�W�O�w�]�g�c�Ѽƪ����f��� ****/

// �гy�g�c�ж��A�� VIRTUAL_D �եΡC
nomask object query_maze_room(string str)
{
	int random_rate = 20;	// �ж�����m npc ���i���
	int idx,x,y,exits;
	object ob;
	string f;

	if( previous_object() && (geteuid(previous_object()) != ROOT_UID) )
		return 0;

	if(!stringp(str) || str == "")
		return 0;

	if(!maze_built)	// �g�c���إ�
		create_maze();
	if(!maze_built)
		return 0;

	if(str == "entry")	// �g�c�J�f�ж�
	{
		f = inherit_rooms[random(sizeof(inherit_rooms))];

		ob = new(f);
		if(!ob)
			return 0;
		ob->set("virtual_room",1);
		ob->set("short",entry_short);
		ob->set("long",entry_desc);
		if(is_outdoors)
			ob->set("outdoors",1);
		ob->set(sprintf("exits/%s",link_entry_dir),link_entry_room);
		ob->set(sprintf("exits/%s",reverse_dir[entry_dir]),mroom_fname(enter->x,enter->y));
		if( sizeof(maze_npcs) && (random(100) <= random_rate) )
		{
			ob->set("objects",([
	maze_npcs[random(sizeof(maze_npcs))] : 1,
]));
			ob->setup();
		}
		return ob;
	}

	if(str == "exit")	// �g�c�X�f�ж�
	{
		f = inherit_rooms[random(sizeof(inherit_rooms))];

		ob = new(f);
		if(!ob)
			return 0;

		ob->set("virtual_room",1);
		ob->set("short",exit_short);
		ob->set("long",exit_desc);
		if(is_outdoors)
			ob->set("outdoors",1);
		ob->set(sprintf("exits/%s",link_exit_dir),link_exit_room);
		ob->set(sprintf("exits/%s",entry_dir),
			mroom_fname(leave->x,leave->y));
		if( sizeof(maze_npcs) && (random(100) <= random_rate) )
		{
			ob->set("objects",([
	maze_npcs[random(sizeof(maze_npcs))] : 1,
]));
			ob->setup();
		}
		return ob;
	}

	idx = member_array('/', str);
	if( idx == -1 )
		return 0;

	if(!sscanf(str[0..idx-1],"%d",x))
		return 0;
	if(!sscanf(str[idx+1..],"%d",y))
		return 0;

	if( !exits = all[x][y] )
		return 0;

	f = inherit_rooms[random(sizeof(inherit_rooms))];
	ob = new(f);
	if(!ob)
		return 0;

	ob->set("virtual_room",1);
	ob->set("short",maze_room_short);
	ob->set("long",maze_room_desc[random(sizeof(maze_room_desc))]);
	if(is_outdoors)
		ob->set("outdoors",1);

	if(exits&W)
		ob->set("exits/west",mroom_fname(x-1,y));
	if(exits&E)
		ob->set("exits/east",mroom_fname(x+1,y));
	if(exits&N)
		ob->set("exits/north",mroom_fname(x,y+1));
	if(exits&S)
		ob->set("exits/south",mroom_fname(x,y-1));

	if( (x == enter->x) && (y == enter->y) )
		ob->set(sprintf("exits/%s",entry_dir),
			sprintf("%s/entry",base_name(this_object())));
	if( (x == leave->x) && (y == leave->y) )
		ob->set(sprintf("exits/%s",reverse_dir[entry_dir]),
			sprintf("%s/exit",base_name(this_object())));

	if( sizeof(maze_npcs) && (random(100) <= random_rate) )
	{
		ob->set("objects",([
	maze_npcs[random(sizeof(maze_npcs))] : 1,
]));
		ob->setup();
	}

	return ob;
}

void create()
{
	seteuid(getuid());
}