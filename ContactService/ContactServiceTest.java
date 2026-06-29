import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

public class ContactServiceTest {

    @Test
    public void testAddContact() {
        ContactService service = new ContactService();
        Contact contact = new Contact("12345", "Kyle", "McCrea", "1234567890", "123 Main Street");

        assertTrue(service.addContact(contact));
        assertEquals(contact, service.getContact("12345"));
    }

    @Test
    public void testAddDuplicateContact() {
        ContactService service = new ContactService();
        Contact contact1 = new Contact("12345", "Kyle", "McCrea", "1234567890", "123 Main Street");
        Contact contact2 = new Contact("12345", "John", "Smith", "0987654321", "456 Main Street");

        assertTrue(service.addContact(contact1));
        assertFalse(service.addContact(contact2));
    }

    @Test
    public void testDeleteContact() {
        ContactService service = new ContactService();
        Contact contact = new Contact("12345", "Kyle", "McCrea", "1234567890", "123 Main Street");

        service.addContact(contact);

        assertTrue(service.deleteContact("12345"));
        assertNull(service.getContact("12345"));
    }

    @Test
    public void testUpdateFirstName() {
        ContactService service = new ContactService();
        Contact contact = new Contact("12345", "Kyle", "McCrea", "1234567890", "123 Main Street");

        service.addContact(contact);
        assertTrue(service.updateFirstName("12345", "John"));
        assertEquals("John", service.getContact("12345").getFirstName());
    }

    @Test
    public void testUpdateLastName() {
        ContactService service = new ContactService();
        Contact contact = new Contact("12345", "Kyle", "McCrea", "1234567890", "123 Main Street");

        service.addContact(contact);
        assertTrue(service.updateLastName("12345", "Smith"));
        assertEquals("Smith", service.getContact("12345").getLastName());
    }

    @Test
    public void testUpdatePhone() {
        ContactService service = new ContactService();
        Contact contact = new Contact("12345", "Kyle", "McCrea", "1234567890", "123 Main Street");

        service.addContact(contact);
        assertTrue(service.updatePhone("12345", "0987654321"));
        assertEquals("0987654321", service.getContact("12345").getPhone());
    }

    @Test
    public void testUpdateAddress() {
        ContactService service = new ContactService();
        Contact contact = new Contact("12345", "Kyle", "McCrea", "1234567890", "123 Main Street");

        service.addContact(contact);
        assertTrue(service.updateAddress("12345", "456 Main Street"));
        assertEquals("456 Main Street", service.getContact("12345").getAddress());
    }

    @Test
    public void testUpdateNonexistentContact() {
        ContactService service = new ContactService();

        assertFalse(service.updateFirstName("99999", "John"));
        assertFalse(service.updateLastName("99999", "Smith"));
        assertFalse(service.updatePhone("99999", "0987654321"));
        assertFalse(service.updateAddress("99999", "456 Main Street"));
    }
}
