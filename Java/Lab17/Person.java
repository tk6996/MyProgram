import java.io.Serializable;

public class Person implements Serializable {
    private static final long serialVersionUID = 1L;
    private String name;
    private String address;
    private String phone_number;
    private String email_address;

    Person(String name, String address, String phone_number, String email_address) {
        this.address = address;
        this.email_address = email_address;
        this.name = name;
        this.phone_number = phone_number;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getPhone_number() {
        return phone_number;
    }

    public void setPhone_number(String phone_number) {
        this.phone_number = phone_number;
    }

    public String getEmail_address() {
        return email_address;
    }

    public void setEmail_address(String email_address) {
        this.email_address = email_address;
    }

    @Override
    public String toString() {
        return String.format("Name %s \nAddress %s\nPhone number %s\nEmail Address %s", name, address,
                phone_number.replaceFirst("(\\d{3})(\\d{3})(\\d{4})", "$1-$2-$3"), email_address);
    }
}