import java.util.HashMap;
import java.util.Map;

public class ContactService {
    private final Map<String, Contact> contacts = new HashMap<>();

    public boolean addContact(Contact contact) {
        if (contact == null || contacts.containsKey(contact.getContactId())) {
            return false;
        }
        contacts.put(contact.getContactId(), contact);
        return true;
    }

    public boolean deleteContact(String contactId) {
        return contacts.remove(contactId) != null;
    }

    public boolean updateFirstName(String contactId, String firstName) {
        Contact contact = contacts.get(contactId);
        if (contact == null) return false;
        contact.setFirstName(firstName);
        return true;
    }

    public boolean updateLastName(String contactId, String lastName) {
        Contact contact = contacts.get(contactId);
        if (contact == null) return false;
        contact.setLastName(lastName);
        return true;
    }

    public boolean updatePhone(String contactId, String phone) {
        Contact contact = contacts.get(contactId);
        if (contact == null) return false;
        contact.setPhone(phone);
        return true;
    }

    public boolean updateAddress(String contactId, String address) {
        Contact contact = contacts.get(contactId);
        if (contact == null) return false;
        contact.setAddress(address);
        return true;
    }

    public Contact getContact(String contactId) {
        return contacts.get(contactId);
    }
}
