int test()
{
	mapping info;
	object ob = find_player("opek");
	if( !ob ) return 0;

	info = ([
	"level": 1,
	"title": "�Ѧa�|�@������",
	"info1": "�L",
	"info2": ctime(time()),
	"info3": this_player()->name_id(1)
	]);
	CLUB_D->add_member("sky",getuid(ob),info);
	return 1;
}
