/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <Generafor.hpp>
#include <FileSystemPlusPlus.h>
#include <ExecutePlusPlus.hpp>

ExecutePlusPlus exec;

void
Generafor::HelpFunction(char* arg) {
	std::cout << arg <<  " [arguments]\n" 
	<< "arguments:\n" <<
	" --g: Generate application.\n" <<
	" --b: Build application.\n";
}


void 
Generafor::GeneratorInfo() {
	std::cout << "Welcome, This is Generafor.\n" <<
		"What's your application's name? : ";
	std::getline(std::cin, app_name);
	std::cout << "Application name/Length: " << app_name <<
	" " << app_name.length() << "\n";
	
	std::cout << app_name + "'s website : ";
	std::getline(std::cin, app_website);
	
	std::cout << app_name + "'s window subtitle: ";
	std::getline(std::cin, app_subtitle);
	
	std::cout << "Generating code.\n";
	
	app_data = "/* Use Gtk and Webkit namespaces */\n"
			"using Gtk;\n"
			"using WebKit;\n"
			"\n"
			"public class Discorder : Window {\n"
			"\t/* Set Window title */\n"
			"    private const string TITLE = \"" + app_name + "\";\n"
			"    private const string SUBTITLE = \"" + app_subtitle + "\";\n"
			"    \n"
			"    /* Default URL */\n"
			"    private const string DEFAULT_URL = \"" + app_website + "\";\n"
			"    \n"
			"    /* Default protocol */\n"
			"    private const string DEFAULT_PROTOCOL = \"http\";\n"
			"\n"
			"    private Regex protocol_regex;\n"
			"    \n"
			"    private WebView web_view;\n"
			"    private ToolButton _discorder_button; /* As a home button */\n"
			"    \n"
			"\tprivate HeaderBar headerBar;\n"
			"\t\n"
			"\tprivate WebContext webContext;\n"
			"\tprivate CookieManager cookieManager;\n"
			"\t\n"
			"\tprivate string cookie_data = GLib.Environment.get_home_dir() + \"/.config/discorder/cookies.discorder\";\n"
			"\t\n"
			"\tpublic Discorder() {\n"
			"    \theaderBar = new HeaderBar();\n"
			"\n"
			"    \twebContext = new WebContext();\n"
			"\n"
			"        headerBar.set_title (Discorder.TITLE);\n"
			"\t\theaderBar.set_subtitle (Discorder.SUBTITLE);\n"
			"        headerBar.set_show_close_button (true);\n"
			"\t\t\n"
			"\n"
			"       this.set_default_size(800, 600);\n"
			"    \n"
			"        \n"
			"        try {\n"
			"            this.protocol_regex = new Regex(\".*://.*\");\n"
			"        } catch (RegexError e) {\n"
			"            critical(\"%s\", e.message);\n"
			"        }\n"
			"\t\t\n"
			"        create_widgets();\n"
			"        connect_signals();\n"
			"  \n"
			"    }\n"
			"\n"
			"    private void create_widgets() {\n"
			"        Gtk.Image img = new Gtk.Image.from_file(\"/usr/share/pixmaps/discorder/discorder_32.png\");\n"
			"\t\tthis._discorder_button = new Gtk.ToolButton(img, null);\n"
			"        \n"
			"        \n"
			"\t\theaderBar.pack_start(this._discorder_button);\n"
			"        \n"
			"        this.set_titlebar(headerBar);\n"
			" \n"
			"\n"
			"    \tcookieManager = webContext.get_cookie_manager();\n"
			"    \tcookieManager.set_persistent_storage(this.cookie_data, CookiePersistentStorage.TEXT);\n"
			"    \tweb_view = new WebView.with_context(webContext);\n"
			"    \t\n"
			"    \tprint(\"Data: \" + this.cookie_data);\n"
			"        \n"
			"        var scrolled_window = new ScrolledWindow(null, null);\n"
			"        \n"
			"        scrolled_window.set_policy(PolicyType.AUTOMATIC, PolicyType.AUTOMATIC);\n"
			"        scrolled_window.add(this.web_view);\n"
			"        \n"
			"\n"
			"        var box = new Box(Gtk.Orientation.VERTICAL, 0);\n"
			"        box.pack_start(scrolled_window, true, true, 0);\n"
			"        add(box);\n"
			"    }\n"
			"\n"
			"    private void connect_signals() {\n"
			"        this.destroy.connect(Gtk.main_quit);\n"
			"        \n"
			"        this._discorder_button.clicked.connect(discorder_button);\n"
			"    }\n"
			"\n"
			"\tprivate void discorder_button() {\n"
			"\t\tthis.web_view.load_uri(DEFAULT_URL);\n"
			"\t}\n"
			"\t\n"
			"\tpublic bool IsExist(string _directory) {\n"
			"    \tif (GLib.FileUtils.test(_directory, GLib.FileTest.EXISTS)) {\n"
			"\t\t\treturn true;\n"
			"\t\t}\n"
			"\t\t\n"
			"\t\treturn false;\n"
			"    }\n"
			"\t\n"
			"\tpublic void AddText(string _directory, string data) {\n"
			"\t\ttry {\n"
			"\t\t\tFileUtils.set_contents(_directory, data);\n"
			"\t\t} catch(Error e) {\n"
			"    \t  \tstderr.printf (\"Error: %s\\n\", e.message);\n"
			"\t\t}\n"
			"\t}\n"
			"\t\n"
			"    public void start() {\n"
			"        show_all();\n"
			"        this.web_view.load_uri(DEFAULT_URL);\n"
			"    }\n"
			"\n"
			"    public static int main(string[] args) {\n"
			"        Gtk.init(ref args);\n"
			"\n"
			"        var browser = new Discorder();\n"
			"        browser.start();\n"
			"\n"
			"        Gtk.main();\n"
			"\n"
			"        return 0;\n"
			"    }\n"
			"}";
		
		std::cout << "Starting. Generator()\n";
		Generator();
}

void
Generafor::Generator() {
	std::cout << "Replacing app_name.\n";
	std::cout << "Add app_website.\n";
	
	std::cout << "Creating file..\n";
	
	if(fsplusplus::IsExistFile("Generafor.vala") != true)
		fsplusplus::CreateFile("Generafor.vala", app_data);
	else
		std::cout << "Error. File is exist.\n";
	
	if(fsplusplus::IsExistFile("Generafor.vala") == true) {
		std::cout << "Nice!\n" <<
		"Do you want to build it? (y/n) : ";
		
		char ch = getchar();
		
		if(ch == 'y' || ch == 'Y')
			Build();			
		else
			std::cout << "Aborted.\n";
	}
}

void 
Generafor::Build() {
	exec.ExecuteName("Generafor");
	exec.RunFunction("valac --pkg gtk+-3.0 --pkg webkit2gtk-4.0 Generafor.vala -o app");
	exec.RunFunction("./app");
}

int main(int argc, char** argv) {
	Generafor main;
	
	if(argc < 2)
		main.HelpFunction(argv[0]);
	else {
		std::string _data(argv[1]);
		
		if(_data == "--g")
			main.GeneratorInfo();
		else if(_data == "--b")
			main.Build();
	}
	
	return 0;
}
