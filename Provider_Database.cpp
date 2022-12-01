// Ashton Sawyer 11/1 
#include "Provider_Database.hpp"

Provider_Database::Provider_Database() = default;

Provider_Database::Provider_Database(Provider_Directory & d) {
    this->data_filename = FILENAME;
	std::ifstream in_file(data_filename);
	if (!in_file.is_open()) {
		std::cout << "Error: Unable to open file" << std::endl;
		return;
	}

	nlohmann::json j;
	in_file >> j;
	init(j, d);
}

Provider_Database::Provider_Database(std::string file_name, Provider_Directory& d) {
	load_file(file_name, d);
}

Provider_Database::Provider_Database(nlohmann::json j, Provider_Directory & d) {
	init(j, d);
}

Provider_Database::~Provider_Database() {
	to_file();

	int len = pids.size();
	for (int i = 0; i < len; ++i) {
		delete table[pids[i]];
	}
}

//return false for no match, true for match
bool Provider_Database::validate_pid(std::string pid) {
	if (table.contains(pid))
		return true;
	return false;
}

bool Provider_Database::get_provider(std::string pid, Provider & to_fill) {
	if (!table.contains(pid))
		return false;

	to_fill.copy(*table[pid]);
	return true;
}

int Provider_Database::add_provider() {
	Provider * p = new Provider();
	p->init_provider();
	table[p->get_pid()] = p;
	pids.push_back(p->get_pid());

	std::cout << "Added Provider:" << std::endl;
	std::cout << *p;

	return 0;
}

bool Provider_Database::add_provider(Provider& copy) {
	Provider * p = new Provider(copy);
	table[p->get_pid()] = p;
	pids.push_back(p->get_pid());

	return true;
}

bool Provider_Database::delete_provider(std::string pid) {
	if (!table.contains(pid))
		return false;

	Provider * p = table[pid];
	std::cout << "Deleting Provider:" << std::endl;
	std::cout << *p;
	delete p;
	if (table.erase(pid) == 0) {
		std::cout << "Error: Unable to remove from database" << std::endl;
		return false;
	}

	for (auto value = pids.begin(); value != pids.end(); ++value) {
		if (*value == pid) {
			pids.erase(value);
			break;
		}
	}

	return true;
}

bool Provider_Database::edit_provider(std::string pid, const Provider & to_copy) {
	if (!table.contains(pid))
		return false;

	Provider * p = table[pid];
	p->copy(to_copy);
	return true;
}

void Provider_Database::to_file() {
	std::ofstream out_file("assets/provider_database.json");

	for (int i = 0; i < pids.size(); ++i) {
		out_file << table[pids[i]]->to_file();
	}
	out_file.close();
	return;
}

void Provider_Database::load_file(std::string file_name, Provider_Directory & d) {
	std::ifstream in_file(file_name);
	if (!in_file.is_open()) {
		std::cout << "Error: Unable to open file" << std::endl;
		return;
	}

	nlohmann::json j;
	in_file >> j;
	in_file.close();

	init(j, d);
}

void Provider_Database::generate_provider_reports(Provider_Directory & d) {
	int len = pids.size();

	for (int i = 0; i < len; ++i) {
		table[pids[i]]->run_report(d);
	}
}

void Provider_Database::generate_single_report(std::string pid, Provider_Directory & d) {
	if (!table.contains(pid)) {
		std::cout << "Error: Provider doesn't exist" << std::endl;
		return;
	}

	table[pid]->run_report(d);
	return;
}

int Provider_Database::display_all() {
	int len = pids.size();

	for (int i = 0; i < len; ++i) {
		std::cout << *table[pids[i]] << std::endl;
	}
	return table.size();
}

void Provider_Database::init(nlohmann::json j, Provider_Directory & d) {
	using json = nlohmann::json;

	// elm = Provider in json array
	for (auto& elm : j.items()) {
		json object = elm.value();
		Provider * p = new Provider(object, d);
		table[p->get_pid()] = p;
		pids.push_back(p->get_pid());
	}
}
