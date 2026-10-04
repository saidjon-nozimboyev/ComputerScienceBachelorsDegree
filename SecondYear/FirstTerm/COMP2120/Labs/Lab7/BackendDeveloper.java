public class BackendDeveloper extends Developer {

    public BackendDeveloper(String name, int id, double salary, String role, String programmingLanguage) {
        super(name, id, salary, role, programmingLanguage);
    }

    @Override
    public void performDuties() {
        System.out.println(name + " is building APIs and ensuring database integration.");
    }

    public void optimizeDatabase() {
        System.out.println(name + " is optimizing database queries for better performance.");
    }
}