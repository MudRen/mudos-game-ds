// virtuald.c
//
// This object is the virtual object server of ES2 mudlib.
//
// By Annihilator (07/06/95)
#define VSERVER "/adm/daemons/virtual/server"
void create()
{
	seteuid(getuid());
}

// This function is called by master object to return the "virtual" object
// of <file> when dirver failed to find such a file.
// �եε�������(�Ȯɩ����w�����D) Luky

nomask object compile_object(string file)
{
   string name, server;
//   CHANNEL_D->do_channel(this_object(), "sys", "ready to compile_object("+file+").");
   if (sscanf(file, "u/%*s/%s/%*s",name))
      server = user_path(name) + "virtual/server";
   if (file_size(server + ".c") == -1)
      server = VSERVER;
   return (object)call_other(server,"compile_object",file);
}

void clean_up()
{
   destruct(this_object());
}

string channel_id() {	return "Virtuald"; }
