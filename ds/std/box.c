// equip.c
#include <box.h>
inherit ITEM;

int cover_status;
int cover_durable;
int lock_status;
int lock_level;
int lock_durable;

string *keys=({});

int is_box() { return 1; }

void setup()
{
	::setup();
        if(query_max_encumbrance() < 1 ) set_max_encumbrance(999999);
        if(query_max_capacity() < 1) set_max_capacity(99);
        if(!query("cover_name")) set("cover_name","�\\�l");
        if(lock_level<1 ) lock_level=1;
        if(lock_durable<1 ) lock_durable=100;
        if(cover_durable<1 ) cover_durable=100;
}

int can_access_box()
{
	if(cover_status==COVER_CLOSED) return 0;
	else return 1;
}

int query_cover_status()
{
	return cover_status;
}

int query_lock_status()
{
	return lock_status;
}

int set_cover(int new_status)
{
	cover_status=new_status;
	return new_status;
}

int set_lock(int new_status)
{
	lock_status=new_status;
	return new_status;
}

int close_cover()
{
	if(cover_status==COVER_OPENED)
	{
		cover_status=COVER_CLOSED;
		return 1;
	}
	return cover_status;
}

int open_cover()
{
	if(cover_status==COVER_CLOSED)
	{
		if(lock_status==LOCK_CLOSED) return lock_status;
		cover_status=COVER_OPENED;
		return 1;
	}
	else return cover_status;
}

int disable_cover()
{
	if(cover_status==COVER_NONE || cover_status==COVER_SMASHED) return cover_status;
	cover_status=COVER_SMASHED;
	return 1;
}

int fix_cover()
{
	if(cover_status!=COVER_SMASHED) return cover_status;
	cover_durable=50+random(50);
	cover_status=COVER_OPENED;
	return 1;
}

varargs int open_lock(object key)
{
	if(cover_status!=COVER_CLOSED) return cover_status;
	if(lock_status!=LOCK_CLOSED) return lock_status;
	if(key && sizeof(keys))
	{
		if(member_array(base_name(key),keys)==-1)
		return 0;
	}
	lock_status=LOCK_OPENED;
	return 1;
}

varargs int close_lock(object key)
{
	if(cover_status!=COVER_CLOSED) return cover_status;
	if(lock_status!=LOCK_OPENED) return lock_status;
	if(key && sizeof(keys))
	{
		if(member_array(base_name(key),keys)==-1)
		return 0;
	}
	lock_status=LOCK_CLOSED;
	return 1;
}

int disable_lock()
{
	if(lock_status==LOCK_NONE || lock_status==LOCK_SMASHED) return lock_status;
	lock_status=LOCK_SMASHED;
	return 1;
}

int fix_lock()
{
	if( lock_status!=LOCK_SMASHED) return lock_status;
	cover_durable=50+random(50);
	lock_status=LOCK_OPENED;
	return 1;
}

nomask void set_keys(string *key_files)
{
	keys=key_files;
	return;
}

nomask void add_keys(string key_file)
{
	keys+=({key_file});
	return;
}

nomask void set_lock_level(int level)
{
	lock_level=level;
	return;
}

int query_lock_level()
{
	return lock_level;
}

varargs int damage_cover(int damage,object me)
{
	if(me) this_object()->set_temp("cover_damage_from",me);
	if(cover_status!=COVER_CLOSED) return cover_status;
	cover_durable-=damage;
	if(cover_durable < 1)
	{
		cover_status=COVER_SMASHED;
		return cover_status;
	}
	return 1;
}

varargs int damage_lock(int damage,object me)
{
	if(me) this_object()->set_temp("lock_damage_from",me);
	if(cover_status!=COVER_CLOSED) return cover_status;
	lock_durable-=damage;
	if(lock_durable < 1)
	{
		lock_status=LOCK_SMASHED;
		return lock_status;
	}
	return 1;
}

string show_cover_status()
{
	string str,name,unit,cover;
	name=this_object()->name();
	unit=this_object()->query("unit");
	cover=this_object()->query("cover_name");
	if(cover_status==COVER_NONE) return "�o"+unit+name+"�èS���\\�l�C";
	if(cover_status==COVER_SMASHED) return "�o"+unit+name+"��"+cover+"�w�g�a�F�C";
	if(cover_status==COVER_CLOSED)
	{
		str="�o"+unit+name+"��"+cover+"�O���_�Ӫ�";
		if(lock_status==LOCK_OPENED) str+="�A���G�èS���Q��W";
		else if(lock_status==LOCK_CLOSED) str+="�A�ӥB�w�g�Q�W�F��";
		else if(lock_status==LOCK_SMASHED) str+="�A��]�w�g�d���F�L�k���}";
		str+="�C\n";
	}
	
	if(cover_status==COVER_OPENED)
	{
		str="�o"+unit+name+"��"+cover+"�O���}��";
		str+="�C\n";
	}
	return str;
}

/* int query_autoload() { return 0; } */