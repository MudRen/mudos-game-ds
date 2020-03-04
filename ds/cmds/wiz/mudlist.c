// mudlist.c

#include <net/daemons.h>
#include <net/macros.h>

inherit F_CLEAN_UP;

#define	SYNTAX	"���O�榡�Rmudlist [<Mud �W��>]\n"

int main(object me, string arg)
{
	mapping mud_list;
	mapping mud_svc;
	mixed *muds;
	string output;
	int loop, size;

	if( !find_object(DNS_MASTER) )
		return notify_fail("�������F�èS���Q���J�M�Х��N�������F���J�C\n");

	//	Obtain mapping containing mud data
	mud_list = (mapping)DNS_MASTER->query_muds();

	// so we recognise ourselves as a DNS mud
	mud_svc = DNS_MASTER->query_svc() + ([ Mud_name() : 0 ]);

	if(!mud_list)
		return notify_fail( MUD_NAME + "�ثe�èS��������W��L Mud ���o�pô�C\n");

	//	Get list of all mud names within name server
	muds = keys( mud_list ) - ({ "DEFAULT" });

	//	Place mudlist into alphabetical format
	muds = sort_array(muds, 1);

	// 	If mudname provided, search server's database for a match
	//	and display its cooresponding address
	if(arg && arg != "") {
		arg = htonn(arg);

		if(!mapp( mud_list[arg] )) {
			write(MUD_NAME + "�èS���M�o�� Mud ���o�pô�C\n");
			return 1;
		}
		printf("���� %s ����T�R\n%O\n", arg, mud_list[arg]);
		return 1;
	}

	output = "Mud �W��\t\t��ں�����}\t      ��\tDNS\tES\n========\t\t============\t      ====\t===\t===\n";

	//	Loop through mud list and store one by one
	for(loop = 0, size = sizeof(muds); loop<size; loop++)
		output += sprintf("%-24s%-18s%8s\t %s \t %s\n", muds[loop], 
			mud_list[muds[loop]]["HOSTADDRESS"],
			mud_list[muds[loop]]["PORT"],
			undefinedp(mud_svc[muds[loop]]) ? "" : "��",
			mud_list[muds[loop]]["MUDLIB"] == "Eastern Stories" ? "��" : "");

	//	Display dumped mudlist output through user's more pager
	this_player()->start_more( output );

	return 1;
}

int help()
{
	write( SYNTAX + "\n"
		"�o�ӫ��O���A�C�X�ثe��o�� Mud ���o�pô������L Mud�C\n"
	);
	return 1;
}

